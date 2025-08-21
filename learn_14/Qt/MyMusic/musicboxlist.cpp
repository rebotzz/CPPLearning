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

void MusicBoxList::loadMusic(const std::vector<std::unordered_map<std::string, std::string>>& musicList)
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
        auto& music_info = m_musicList[(currentIdx + idx) % m_musicList.size()];
        auto box = new MusicBox;
        box->setText(QString::fromStdString(music_info["title"]));
        box->setImage(QString::fromStdString(music_info["cover"]));
        qDebug() << QString::fromStdString(music_info["title"]) << "\n";

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
