#include "resmgr.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMediaPlayer>
#include <QMediaMetaData>

#include <fstream>
#include "json.h"

const QJsonObject &ResMgr::findMusic(int id)
{
    if(musicPool.size() > id && id >= 0) return musicPool[id];
    else throw std::invalid_argument("not find music by this id: " + std::to_string(id));
}

ResMgr &ResMgr::getInstance()
{
    static ResMgr resMgr;
    return resMgr;
}

void ResMgr::loadMusic(std::string path)
{
    // 读取配置文件，加载音乐
    QFile file(QString::fromStdString(path));
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "can't open error!";
        return;
    }
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    QString str = stream.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull())
    {
        qDebug() << "Json格式错误！" << jsonError.error;
        return;
    }

    QJsonArray rootArr = doc.array();
    for(auto val : rootArr)
    {
        qDebug() << val;
        musicPool.push_back(val.toObject());
        // todo：加入歌手描述，分离歌名字和路径；建立查找索引
    }
}

void ResMgr::loadMusic_(const std::string &path)
{
    std::ifstream config_file(path);
    if(config_file.fail())
        return;
    Json::Value root;
    config_file >> root;
    std::string music_path = root.get("music_path", "").asString();
    std::string cover_path = root.get("cover_path", "").asString();
    const auto& music_list = root.get("music_list", Json::arrayValue);
    for (auto& music : music_list)
    {
        std::unordered_map<std::string, std::string> music_info;
        music_info["path"] = music_path + music.get("path", "").asString();
        music_info["cover"] = cover_path + music.get("cover", "").asString();
        auto meta_info = getMusicMetaInfo(music_info["path"]);
        for(auto [k, v] : meta_info)
        {
            music_info[k] = v;
        }
    }
}



ResMgr::ResMgr()
{}

std::unordered_map<std::string, std::string> ResMgr::getMusicMetaInfo(const std::string &path)
{
    QMediaPlayer player;
    player.setMedia(QUrl::fromLocalFile(QString::fromStdString(path)));
    std::string title = player.metaData(QMediaMetaData::Title).toString().toStdString();
    std::string author = player.metaData(QMediaMetaData::Author).toString().toStdString();
    std::string album = player.metaData(QMediaMetaData::AlbumTitle).toString().toStdString();
    std::string duration = std::to_string(player.metaData(QMediaMetaData::Duration).toString().toUInt());
    return {{"title", title},
            {"author", author},
            {"album", album},
            {"duration", duration}};
}










