#include "musicbox.h"
#include "ui_musicbox.h"
#include <QPropertyAnimation>
#include <QDebug>

MusicBox::MusicBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicBox)
{
    ui->setupUi(this);

    // 为音乐封面安装事件拦截器：目标：cover，方法：this->eventFilter(); 这里的this似乎作用是方便调用this->eventFilter()
    ui->cover->installEventFilter(this);
}

MusicBox::~MusicBox()
{
    delete ui;
}

void MusicBox::setText(const QString &text)
{
    ui->text->setText(text);
}

void MusicBox::setImage(const QString &path)
{
    ui->cover->setPixmap(QPixmap(path));
}

bool MusicBox::eventFilter(QObject *watched, QEvent *event)
{

    // 事件过滤器，拦截鼠标进入/离开音乐封面事件，添加封面动画效果
    if(watched == ui->cover)
    {
        int w = ui->cover->rect().width();
        int h = ui->cover->rect().height();
        if(event->type() == QEvent::Enter)
        {
            auto anim = new QPropertyAnimation(ui->cover, "geometry", this);
            anim->setDuration(100);
            anim->setStartValue(QRect(10, 10, w, h));
            anim->setEndValue(QRect(10, 0, w, h));
            anim->start(QAbstractAnimation::DeleteWhenStopped);
            connect(anim, &QPropertyAnimation::finished, this, [=] { qDebug() << "delete anim 1"; });

            // 拦截成功
            return true;
        }
        else if(event->type() == QEvent::Leave)
        {
            auto anim = new QPropertyAnimation(ui->cover, "geometry", this);
            anim->setDuration(150);
            anim->setStartValue(QRect(10, 0, w, h));
            anim->setEndValue(QRect(10, 10, w, h));
            anim->start(QAbstractAnimation::DeleteWhenStopped);
            connect(anim, &QPropertyAnimation::finished, this, [=] { qDebug() << "delete anim 2"; });

            // 拦截成功
            return true;
        }

    }

    // 拦截失败，继续传递事件(责任链模式)
    return QWidget::eventFilter(watched, event);
}
