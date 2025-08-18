#include "musicinfoitem.h"
#include "ui_musicinfoitem.h"

MusicInfoItem::MusicInfoItem(QWidget *parent, const QString &path, const QString &music_name,
                             const QString &singer, const QString &album) :
    QWidget(parent),
    ui(new Ui::MusicInfoItem)
{
    ui->setupUi(this);

    // 初始化回调
    connect(ui->favor_icon_btn, &QPushButton::clicked, this, &MusicInfoItem::onFavorBtnClick);
}


MusicInfoItem::~MusicInfoItem()
{
    delete ui;
}

void MusicInfoItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    // 播放音乐
}

void MusicInfoItem::onFavorBtnClick()
{
    // 设置喜欢标记
    setFavor(!getFavor());
    auto icon_path = getFavor() ? ":/resources/images/icon/like_2.png" : ":/resources/images/icon/like_3.png";
    auto icon = QPixmap(icon_path);
    ui->favor_icon_btn->setIcon(icon);

}
