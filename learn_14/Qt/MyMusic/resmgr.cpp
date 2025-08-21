#include "resmgr.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QString>

#include "json/json.h"
#include <fstream>
#include <iostream>


ResMgr::ResMgr()
{}

const ResMgr::MuiscInfoDict &ResMgr::findMusic(uint id)
{
    if(music_pool.size() > id) return music_pool[id];
    else throw std::invalid_argument("not find music by this id: " + std::to_string(id));
}

ResMgr &ResMgr::getInstance()
{
    static ResMgr resMgr;
    return resMgr;
}


void ResMgr::loadMusic(const std::string &path)
{
    std::ifstream config_file(path);
    if(config_file.fail())
        return;
    Json::Value root;
    config_file >> root;
    std::string music_path = root.get("music_path", "").asString();
    std::string cover_path = root.get("cover_path", "").asString();
    const auto& music_list = root.get("music_list", "");
    for (auto& music : music_list)
    {
        std::unordered_map<std::string, std::string> music_info;
        music_info["path"] = music_path + music.get("file", "").asString();
        music_info["cover"] = cover_path + music.get("cover", "").asString();
        auto meta_info = getMusicMetaInfo(music_info["path"]);
        for(auto [k, v] : meta_info)
        {
            qDebug() << QString::fromStdString(k) << " " << QString::fromStdString(v) << "\n";
            music_info[k] = v;
        }
        if(music_info["title"].empty())
        {
            auto file_name = music.get("file", "").asString();
            auto title = file_name.substr(0, file_name.rfind('.'));
            music_info["title"] = title;
        }
        if(music_info["album"].empty())
        {
            music_info["album"] = "unkown";
        }
        if(music_info["author"].empty())
        {
            music_info["author"] = "unkown";
        }
        music_pool.push_back(music_info);

        for(auto [k, v]: music_info)
        {


//            std::cout << k << " " << v << "\n";
            qDebug() << QString::fromStdString(k) << " " << QString::fromStdString(v) << "\n";
        }
    }
}


ResMgr::MuiscInfoDict ResMgr::getMusicMetaInfo(const std::string &path)
{
    QMediaPlayer player;
    player.setMedia(QUrl::fromLocalFile(QString::fromStdString(path)));
    std::string title = player.metaData(QMediaMetaData::Title).toString().toStdString();
    std::string author = player.metaData(QMediaMetaData::Author).toString().toStdString();
    std::string album = player.metaData(QMediaMetaData::AlbumTitle).toString().toStdString();
    auto duration = player.metaData(QMediaMetaData::Duration).toString();
    qDebug() << "-------------------duration: " << duration << " \n";
//    if (duration <= 0)
//        throw "duration < 0";
    return {{"title", trim(title)},
            {"author", trim(author)},
            {"album", trim(album)},
        {"duration", trim(duration.toStdString())}};
}

ResMgr::MuiscInfoDict ResMgr::getMusicMetaInfo2(const std::string &path)
{
    // TODO: 更换获取歌曲时常的接口
}

std::string ResMgr::trim(const std::string &str, const std::string& sep)
{
    if(str.size() <= 0) return str;
    auto begin = str.find_first_not_of(sep);
    auto end = str.find_last_not_of(sep);
    return str.substr(begin, end - begin + 1);
}










