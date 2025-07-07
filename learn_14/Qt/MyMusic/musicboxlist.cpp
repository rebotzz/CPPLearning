#include "musicboxlist.h"
#include "ui_musicboxlist.h"


MusicBoxList::MusicBoxList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicBoxList)
{
    ui->setupUi(this);
}

MusicBoxList::~MusicBoxList()
{
    delete ui;
}
