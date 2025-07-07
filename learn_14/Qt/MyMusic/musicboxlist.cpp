#include "musicboxlist.h"
#include "ui_musicboxlist.h"
#include "musicbox.h"
#include <QDebug>
#include <QString>

MusicBoxList::MusicBoxList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicBoxList)
{
    ui->setupUi(this);

    auto box = new MusicBox;
    box->setText("夜航星");
    box->setImage("../MyMusic/resources/024.png");
    ui->upList->layout()->addWidget(box);

}

MusicBoxList::~MusicBoxList()
{
    delete ui;
}
