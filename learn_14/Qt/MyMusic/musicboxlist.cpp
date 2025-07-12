#include "musicboxlist.h"
#include "ui_musicboxlist.h"
#include "musicbox.h"
#include <QDebug>
#include <QString>
#include <string>
#include <fstream>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>

MusicBoxList::MusicBoxList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicBoxList)
{
    ui->setupUi(this);

    // debug
//    ui->upList->hide();
//    ui->downList->hide();
}

MusicBoxList::~MusicBoxList()
{
    delete ui;
}

void MusicBoxList::loadMusic(const std::vector<QJsonObject>& musicList)
{
    for(auto& obj : musicList)
    {
        m_musicList.push_back(obj);
    }
    refresh();
}

void MusicBoxList::refresh()
{
    clearMusicBox();
    int idx = 0;
    while(idx < lineMusicCount * (onlyUpLine ? 1 : 2))
    {
        QJsonObject& musicDesc = m_musicList[(currentIdx + idx) % m_musicList.size()];
        QString mus_path = musicDesc["music_path"].toString();
        QString cover_path = musicDesc["cover"].toString();

        auto box = new MusicBox;
        auto music_name = musicDesc["music_path"].toString().toStdString();
        music_name = music_name.substr(music_name.find_last_of("\\") + 1);
        music_name = music_name.substr(0, music_name.find_last_of('.'));
        box->setText(QString::fromStdString(music_name));
        box->setImage(cover_path);

        if(onlyUpLine || idx < lineMusicCount)
        {
            ui->upList->layout()->addWidget(box);
        }
        else
        {
            ui->downList->layout()->addWidget(box);
        }
        idx++;
    }
}

void MusicBoxList::setOnlyUpLine(bool flag)
{
     onlyUpLine = flag;
     if(onlyUpLine)
     {
         ui->downList->hide();  // debug:MusicBoxList的最小尺寸不写500，改为0，不然隐藏后下方会是空白
     }
}

void MusicBoxList::clearMusicBox()
{
    clearLayout(ui->upList->layout());
    clearLayout(ui->downList->layout());
}

void MusicBoxList::clearLayout(QLayout *layout)
{
    if (!layout) return;

    // 先移除所有widgets;    debug: takeAt替代itemAt
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (QWidget* widget = item->widget()) {
            widget->hide();
            widget->deleteLater();  // 安全删除
        }
        delete item;  // 必须删除布局项
    }

    // 强制刷新布局
    layout->invalidate();
    layout->update();
    layout->activate();
}

void MusicBoxList::on_leftButton_clicked()
{
    currentIdx -= 1;
    if(currentIdx < 0) currentIdx = m_musicList.size() - 1;
    refresh();
}

void MusicBoxList::on_rightButton_clicked()
{
    currentIdx = (currentIdx + 1) % m_musicList.size();
    refresh();
}
