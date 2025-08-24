#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "resmgr.h"
#include "volumetool.h"

#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QFileDialog>
#include <QDir>

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
    initOtherWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMusicBoxList()
{
    auto& music_pool = ResMgr::getInstance().getMusicPool();
    int rec_music_count = music_pool.size() / 2;

    ResMgr::MuiscInfoDictList rec_music_list(music_pool.begin(), music_pool.begin() + rec_music_count);
    ResMgr::MuiscInfoDictList sup_music_list(music_pool.begin() + rec_music_count, music_pool.end());
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

void MainWindow::initOtherWidgets()
{
    // 音量调节控件初始化
    volume_tool = new VolumeTool(this);
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
    stack_name_id_map = {{"推荐", 0}, {"电台", 1}, {"探索", 2}, {"我喜欢", 3}, {"最近播放", 4}, {"本地下载", 5}};
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

void MainWindow::on_volume_clicked()
{
    // 先要调整窗口的显示位置，否则该窗口在主窗口的左上角
    // 1. 获取该按钮左上角的图标
    // 2. 计算volume窗口的左上角位置
    QPoint point = ui->volume->mapToGlobal(QPoint(ui->volume->width() / 2, 0));
    auto volume_left_top = point - QPoint(volume_tool->width() / 2, volume_tool->height());
    volume_tool->move(volume_left_top);
    volume_tool->show();
}

void MainWindow::on_addLocal_clicked()
{
    // 1.创建文件对话框
    // 2.设置模式
    // 3.设置文件类型过滤
    // 4.设置默认路径
    // 5.模态，接受文件url
    QFileDialog file_dialog(this);
    file_dialog.setWindowTitle("添加本地音乐");

    file_dialog.setAcceptMode(QFileDialog::AcceptOpen);
    file_dialog.setFileMode(QFileDialog::ExistingFiles);

    QStringList mime_type_list;
    mime_type_list << "application/octet-stream";
    file_dialog.setMimeTypeFilters(mime_type_list);

    QDir dir(QDir::currentPath());
    dir.cdUp();
    file_dialog.setDirectory(dir.path());

    if(file_dialog.exec() == QFileDialog::Accepted)
    {
        QList<QUrl> music_list = file_dialog.selectedUrls();
        // 处理音乐。。。
        qDebug() << "load music count: " << music_list.size() << "\n";
        for(auto x : music_list)
        {
            qDebug() << x.url() << "\n";
        }

        ui->stackedWidget->setCurrentIndex(stack_name_id_map["本地下载"]);
    }
}



















