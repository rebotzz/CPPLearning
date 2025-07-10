#include "resmgr.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
#include <QDebug>

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

ResMgr::ResMgr()
{}
