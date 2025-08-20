#include "musiclistpage.h"
#include "ui_musiclistpage.h"
#include "musicinfoitem.h"

#include <fstream>
#include <string>


#include <QJsonArray>
#include <QJsonObject>



MusicListPage::MusicListPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicListPage)
{
    ui->setupUi(this);

    // 测试
    auto song = new MusicInfoItem(this, "path", "test song", "me", "unkown");
    auto item = new QListWidgetItem(ui->musicList);
    ui->musicList->setItemWidget(item, song);
//    ui->musicList->addItem(song);
}

MusicListPage::~MusicListPage()
{
    delete ui;
}

void MusicListPage::loadMusicList(const std::string& config_path)
{
    // 读取歌单
    // 字段：歌手、封面、专辑、路径、是否喜欢

    auto config_file = std::ifstream(config_path);
    if(config_file.fail())
        return;
    std::string data;
    std::string line;
    while(std::getline(config_file, line))
    {
        data += line;
        data += "\n";
    }


    config_file.close();
}
