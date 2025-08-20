#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "resmgr.h"

#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>

#include <fstream>
#include <string>
#include <unordered_set>
#include <random>
#include <algorithm>

#include "musiclistpage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化窗口
    initWindow();
    // 初始化信号与槽连接
    initConnect();

    // 初始化音乐控件
    initMusicBoxList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMusicBoxList()
{
    auto& musicPool = ResMgr::getInstance().getMusicPool();
    int rec_music_count = musicPool.size() / 2;

    std::vector<QJsonObject> rec_music_list(musicPool.begin(), musicPool.begin() + rec_music_count);
    std::vector<QJsonObject> sup_music_list(musicPool.begin() + rec_music_count, musicPool.end());
    srand(time(nullptr));
    std::random_shuffle(rec_music_list.begin(), rec_music_list.end());
    std::random_shuffle(sup_music_list.begin(), sup_music_list.end());
//    std::sample(musicPool.begin(), musicPool.begin() + rec_music_count, rec_music_list.begin(), 8,
//                std::default_random_engine({std::random_device()));

    ui->recommendBox->setOnlyUpLine(true);
    ui->recommendBox->loadMusic(rec_music_list);
    ui->supplyBox->loadMusic(sup_music_list);

    std::vector<std::pair<MusicBoxList*, MusicBoxList*>> tmp_box_arr = {{ui->radioBox_1, ui->radioBox_2},
                                                                    {ui->exploreBox_1, ui->exploreBox_2}};
    for(auto& kv : tmp_box_arr)
    {
        std::random_shuffle(rec_music_list.begin(), rec_music_list.end());
        std::random_shuffle(sup_music_list.begin(), sup_music_list.end());
        kv.first->setOnlyUpLine(true);
        kv.first->loadMusic(rec_music_list);
        kv.second->loadMusic(sup_music_list);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        return;
    }
    QMainWindow::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(Qt::LeftButton == event->buttons())  // buttons() 【伴随】鼠标事件的按键
    {
        auto new_pos = event->globalPos() - dragPosition;
        move(new_pos);
        return;
    }
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::initWindow()
{
    // 无边框
//    setWindowFlag(Qt::WindowType::FramelessWindowHint);

    // 窗口阴影效果
    setAttribute(Qt::WA_TranslucentBackground);
    auto shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0);
    shadow_effect->setColor(QColor(0,0,0));
    shadow_effect->setBlurRadius(15);
    setGraphicsEffect(shadow_effect);

    // UI
    // 初始化点击回调
    ui->recommend->initContent(":/resources/images/icon/rec.png", "推荐", 0);
    ui->radio->initContent(":/resources/images/icon/radio.png", "电台", 1);
    ui->explore->initContent(":/resources/images/icon/music.png", "探索", 2);
    ui->myLove->initContent(":/resources/images/icon/like.png", "我喜欢", 3);
    ui->recent->initContent(":/resources/images/icon/recent.png", "最近播放", 4);
    ui->local->initContent(":/resources/images/icon/local.png", "本地下载", 5);

    // 初始化音乐歌单table页面
//    ui->locolPage->loadMusicList()
}

void MainWindow::initConnect()
{
    // 按下左侧按键时，能切换到对应页面
    auto btForms = findChildren<AnimButton*>();
    for(AnimButton* form : btForms)
    {
        connect(form, &AnimButton::click, this, &MainWindow::onBtFormClick);
    }
}

void MainWindow::on_buttonQuit_clicked()
{
    close();
}

void MainWindow::onBtFormClick(int pageId)
{
    // 将没有选中页面的风格恢复
    auto btForms = findChildren<AnimButton*>();
    for(auto btform : btForms)
    {
        if(btform->getPageId() != pageId)
        {
            btform->resetStyleSheet();
            btform->hideAnimation();
            continue;
        }
        btform->showAnimation();
    }
    // 切换到选中页面
    ui->stackedWidget->setCurrentIndex(pageId);

}


void MainWindow::on_buttonMin_clicked()
{
    showMinimized();
}

void MainWindow::on_buttonMax_clicked()
{
    if(!is_maxshow)
    {
        is_maxshow = true;
        showMaximized();
    }
    else
    {
        is_maxshow = false;
        showNormal();
    }

}

void MainWindow::on_buttonSkin_clicked()
{
    auto msg_box = new QMessageBox(this);
    msg_box->setIcon(QMessageBox::Information);
    msg_box->setText("抱歉，暂未支持更换主体");
    msg_box->exec();
}
