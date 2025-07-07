#include "musicbox.h"
#include "ui_musicbox.h"

MusicBox::MusicBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicBox)
{
    ui->setupUi(this);
}

MusicBox::~MusicBox()
{
    delete ui;
}
