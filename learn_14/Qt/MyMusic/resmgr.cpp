#include "resmgr.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QString>
#include <QCoreApplication>

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
    int tmp = 0;
    for (auto& music : music_list)
    {
//        if(tmp++ > 3) break;
        std::unordered_map<std::string, std::string> music_info;
        music_info["path"] = music_path + "/" + music.get("file", "").asString();
        music_info["cover"] = cover_path + "/" + music.get("cover", "").asString();

        auto input = std::ifstream(music_info["path"]);
        if(input.fail())
        {
            // std::cout << "file open error: " << music_info["path"] << "\n";
        }
        input.close();

        auto meta_info = parseMediaMetaMusic(music_info["path"]);
        // qDebug() << "-------------------------------------\n";
        for(auto [k, v] : meta_info)
        {
            // qDebug() << QString::fromStdString(k) << " " << QString::fromStdString(v) << "\n";
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
//            qDebug() << QString::fromStdString(k) << " " << QString::fromStdString(v) << "\n";
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

    return {{"title", trim(title)},
            {"author", trim(author)},
            {"album", trim(album)},
        {"duration", trim(duration.toStdString())}};



}

ResMgr::MuiscInfoDict ResMgr::parseMediaMetaMusic(const std::string &path)
{
    // 1. 创建媒体播放对象



//    return {};
    QMediaPlayer player;

    // 2. 设置媒体源，依靠setMedia方法解析元数据
    auto musicUrl = QUrl::fromLocalFile(QString::fromStdString(path));
    player.setMedia(musicUrl);

    // 3. 因为setMedia不会等待音乐的加载就立马返回
    //    因此在通过mediaMeta方法获取元数据时，需要保证媒体已经添加完毕
    //    可以通过isMetaDataAvailable检测数据是否有效
    //    如果该方法返回true，说明加载完成
//    while(!player.isMetaDataAvailable())
//    {
//        QCoreApplication::processEvents();
//        printf("wait isMetaDataAvailable...\n");
//    }

    // 已经加载完成，可以获取有效的元数据
    QString musicName, musicSinger, musicAlbumn;
    long long duration = 0;
    if(player.isMetaDataAvailable())
    {
        musicName = player.metaData("Title").toString();
        musicSinger = player.metaData("Author").toString();
        musicAlbumn = player.metaData("AlbumTitle").toString();
        duration = player.metaData("Duration").toLongLong();

        QString fileName = musicUrl.fileName();
        // 找-的位置
        int index = fileName.indexOf('-');

        // musicName为""的处理
        if(musicName.isEmpty())
        {
            if(index != -1)
            {
                // "2002年的第一场雪 - 刀郎.mp3"
                musicName = fileName.mid(0, index).trimmed();
            }
            else
            {
                // "2002年的第一场雪.mp3"
                musicName = fileName.mid(0, fileName.indexOf('.')).trimmed();
            }
        }

        // 作者为空
        if(musicSinger.isEmpty())
        {
            if(index != -1)
            {
                musicSinger = fileName.mid(index+1, fileName.indexOf('.')-index-1).trimmed();
            }
            else
            {
                musicSinger = "未知歌手";
            }
        }

        // 专辑名为空
        if(musicAlbumn.isEmpty())
        {
            musicAlbumn = "未知专辑";
        }

        // "2002年的第一场雪 - 刀郎.mp3"
        // qDebug()<<fileName<<musicSinger<<":"<<musicAlbumn<<":"<<duration;
    }

    return {{"title", trim(musicName.toStdString())},
            {"author", trim(musicSinger.toStdString())},
            {"album", trim(musicAlbumn.toStdString())},
            {"duration", trim(std::to_string(duration))}
    };
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










