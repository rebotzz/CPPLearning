#include "musiclistpage.h"
#include "ui_musiclistpage.h"

MusicListPage::MusicListPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicListPage)
{
    ui->setupUi(this);
}

MusicListPage::~MusicListPage()
{
    delete ui;
}
