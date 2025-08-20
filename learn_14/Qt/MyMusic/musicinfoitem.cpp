#include "musicinfoitem.h"
#include "ui_musicinfoitem.h"

#include <QDebug>

MusicInfoItem::MusicInfoItem(QWidget *parent, const QString &path, const QString &music_name,
                             const QString &singer, const QString &album) :
    QWidget(parent),
    ui(new Ui::MusicInfoItem)
{
    ui->setupUi(this);

    this->path = path;
    ui->music_name->setText(music_name);
    ui->singer->setText(singer);
    ui->album_label->setText(album);

    // 初始化回调
    connect(ui->favor_icon_btn, &QPushButton::clicked, this, &MusicInfoItem::onFavorBtnClick);
    setFavorIcon();
}


MusicInfoItem::~MusicInfoItem()
{
    delete ui;
}

void MusicInfoItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 播放音乐
    qDebug() << "播放音乐: " << path;
}

void MusicInfoItem::onFavorBtnClick()
{
    // 设置喜欢标记
    setFavor(!getFavor());
    setFavorIcon();
}

void MusicInfoItem::setFavorIcon()
{
    auto icon_path = getFavor() ? ":/resources/images/icon/like_2.png" : ":/resources/images/icon/like_3.png";
    auto icon = QPixmap(icon_path);
    ui->favor_icon_btn->setIcon(icon);
}
