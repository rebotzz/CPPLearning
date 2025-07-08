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
//    ui->text->setWordWrap(true);
//    ui->text->adjustSize();
//    ui->text->setAlignment(Qt::AlignCenter);
}

void MusicBox::setImage(const QString &path)
{
    // 两种设置方式都行
    auto img = QPixmap(path);
    // 图片放缩
    int cover_w = ui->cover->size().width(), cover_h = ui->cover->size().height();
    int img_w = img.width(), img_h = img.height();
    int min_len_img = std::min(img_w, img_h);
    int min_len_cover = std::min(cover_w, cover_h);
    QSize size;
    if(min_len_img > min_len_cover) // 图片过大
    {
        float scale = std::min(static_cast<float>(img_w) / static_cast<float>(cover_w), static_cast<float>(img_h) / static_cast<float>(cover_h));
        size = QSize(img_w / scale, img_h / scale);
    }
    else size = QSize(cover_w, cover_h);
    img = img.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    ui->cover->setAlignment(Qt::AlignCenter);
    ui->cover->setPixmap(img);

//    ui->cover->setScaledContents(true);
//    ui->cover->setStyleSheet("border-image: url(" + path + ");");     // 路径格式兼容不好
}

bool MusicBox::eventFilter(QObject *watched, QEvent *event)
{

    // 事件过滤器，拦截鼠标进入/离开音乐封面事件，添加封面动画效果
    if(watched == ui->cover)
    {
        int w = ui->cover->rect().width();
        int h = ui->cover->rect().height();

        int offset = ui->margin->rect().width();
        if(event->type() == QEvent::Enter)
        {
            auto anim = new QPropertyAnimation(ui->cover, "geometry", this);
            anim->setDuration(100);
            anim->setStartValue(QRect(offset, offset, w, h));
            anim->setEndValue(QRect(offset, 0, w, h));
            anim->start(QAbstractAnimation::DeleteWhenStopped);
//            connect(anim, &QPropertyAnimation::finished, this, [=] { qDebug() << "delete anim 1"; });

            // 拦截成功
            return true;
        }
        else if(event->type() == QEvent::Leave)
        {
            auto anim = new QPropertyAnimation(ui->cover, "geometry", this);
            anim->setDuration(150);
            anim->setStartValue(QRect(offset, 0, w, h));
            anim->setEndValue(QRect(offset, offset, w, h));
            anim->start(QAbstractAnimation::DeleteWhenStopped);
//            connect(anim, &QPropertyAnimation::finished, this, [=] { qDebug() << "delete anim 2"; });

            // 拦截成功
            return true;
        }

    }

    // 拦截失败，继续传递事件(责任链模式)
    return QWidget::eventFilter(watched, event);
}
