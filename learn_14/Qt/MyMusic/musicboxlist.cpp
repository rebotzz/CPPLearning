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

int MusicBoxList::music_idx = 0;

MusicBoxList::MusicBoxList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicBoxList)
{
    ui->setupUi(this);

    auto box = new MusicBox;
    box->setText("夜航星");
    box->setImage("../MyMusic/resources/024.png");
    ui->upList->layout()->addWidget(box);

    // 读取配置文件，加载音乐
    QString entry_path = "../MyMusic/resources/tmp/";
    QString json_file = entry_path + "list.json";

    QFile file(json_file);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
    qDebug() << "can't open error!";
    return;
    }
    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    QString str = stream.readAll();
    file.close();

    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull()) {
    qDebug() << "Json格式错误！" << jsonError.error;
    return;
    }

    int count = 8, idx = 0;
    QJsonArray rootArr = doc.array();
    for(; music_idx < rootArr.size(); ++music_idx)
    {
        QJsonValue val = rootArr[music_idx];
        QString mus_path = entry_path + val["music_path"].toString();
        QString cover_path = entry_path + val["cover"].toString();
        qDebug() << val;
        qDebug() << "mus: " << mus_path << "  cover: " << cover_path;

        if(idx >= 8) break;
        auto box = new MusicBox;
        auto music_name = val["music_path"].toString().toStdString();
        music_name = music_name.substr(music_name.find_last_of("\\") + 1);
        music_name = music_name.substr(0, music_name.find_last_of('.'));
        box->setText(QString::fromStdString(music_name));
        box->setImage(cover_path);

        if(idx < 4)
        {
            ui->upList->layout()->addWidget(box);
        }
        else
        {
            ui->downList->layout()->addWidget(box);
        }
        idx++;
    }
    file.close();

//    ////////////////////////////
//    QJsonObject rootObj = doc.object();
//    QJsonValue nameValue = rootObj.value("name");
//    qDebug() << "name =" << nameValue.toString();
//    QJsonValue ageValue = rootObj.value("age");
//    qDebug() << "age =" << ageValue.toInt();
//    QJsonValue vipValue = rootObj.value("vip");
//    qDebug() << "vip =" << vipValue.toBool();
//    QJsonValue addressValue = rootObj.value("address");
//    if (addressValue.type() == QJsonValue::Null) {
//    qDebug() << "address = null";
//    }

//    QJsonValue interestValue = rootObj.value("interest");
//    if (interestValue.type() == QJsonValue::Object) {
//    QJsonObject interestObj = interestValue.toObject();
//    QJsonValue basketballValue = interestObj.value("basketball");
//    qDebug() << "basketball =" << basketballValue.toString();
//    QJsonValue badmintonValue = interestObj.value("badminton");
//    qDebug() << "badminton =" << badmintonValue.toString();
//    }

//    QJsonValue colorValue = rootObj.value("color");
//    if (colorValue.type() == QJsonValue::Array) {
//    QJsonArray colorArray = colorValue.toArray();
//    for (int i = 0; i < colorArray.size(); i++) {
//    QJsonValue color = colorArray.at(i);
//    qDebug() << "color =" << color.toString();
//    }
//    }

//    QJsonValue likeValue = rootObj.value("like");
//    if (likeValue.type() == QJsonValue::Array) {
//    QJsonArray likeArray = likeValue.toArray();
//    for (int i = 0; i < likeArray.count(); i++) {
//    QJsonValue likeValueChild = likeArray.at(i);
//    if (likeValueChild.type() == QJsonValue::Object) {
//    QJsonObject likeObj = likeValueChild.toObject();
//    QJsonValue gameLikeValue = likeObj.value("game");
//    qDebug() << "game =" << gameLikeValue.toString();
//    QJsonValue priceLikeValue = likeObj.value("price");
//    qDebug() << "price =" << priceLikeValue.toDouble();
//    }
//    }
//    }
}

MusicBoxList::~MusicBoxList()
{
    delete ui;
}
