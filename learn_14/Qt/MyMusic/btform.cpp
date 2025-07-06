#include "btform.h"
#include "ui_btform.h"

#include <QPropertyAnimation>
#include <vector>

BtForm::BtForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BtForm)
{
    ui->setupUi(this);

    // 初始化动画
    int x_offset = 7;
    int time_offset = 100;
    std::vector<QLabel*> line_list = {ui->line1, ui->line2, ui->line3, ui->line4};
    for(size_t i = 0; i < line_list.size(); ++i)
    {
        initAnimation(line_list[i], 1500 + time_offset * i, QRect(0 + x_offset * i, 20, 3, 0),
                      QRect(0 + x_offset * i,0,3,20),QRect(0 + x_offset * i, 20, 3, 0));
    }
    hideAnimation();
}

BtForm::~BtForm()
{
    delete ui;
}

void BtForm::resetStyleSheet()
{
    ui->btStyle->setStyleSheet("#btStyle:hover{ background: rgba(196, 243, 255, 150);}");
}

void BtForm::showAnimation()
{
    ui->lineBox->show();
//      ui->lineBox->setEnabled(true);
}

void BtForm::hideAnimation()
{
    ui->lineBox->hide();
//    ui->lineBox->setEnabled(false);
}

void BtForm::setContent(QString icon, QString text, int pageId)
{
    ui->icon->setPixmap(QPixmap(icon));
    ui->text->setText(text);
    m_pageId = pageId;
}

void BtForm::mousePressEvent(QMouseEvent* )
{
    // 点击后切换控件颜色，发送点击信号
    ui->btStyle->setStyleSheet("#btStyle{background: rgba(189, 180, 255, 150);} *{color: rgba(255, 255, 255, 255)}");
    emit click(this->m_pageId);
}

void BtForm::initAnimation(QLabel *line, int duration_ms, QRect start, QRect mid, QRect end)
{
    // 创建动画，设置动画持续时间、关键帧(时间百分比，对应的矩形)
    auto animLine = new QPropertyAnimation(line, "geometry", this);
    animLine->setDuration(duration_ms);
    animLine->setKeyValueAt(0, start);
    animLine->setKeyValueAt(0.5, mid);
    animLine->setKeyValueAt(1, end);
    animLine->setLoopCount(-1);
    animLine->start();
}


