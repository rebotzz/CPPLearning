#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "myfiledialog.h"
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>

#include <fstream>
#include <string>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化窗口
    initWindow();
    // 初始化信号与槽连接
    initConnect();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto dialog = new MyFileDialog(this);
    dialog->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);    // 记得释放资源
//    dialog->exec();

    auto path = dialog->getOpenFileName();  // 包括了exec()
    qDebug() << path;

    auto input = std::ifstream(path.toStdString());
    if(input.fail()) return;

    std::string line, text;
    while(std::getline(input, line))
    {
        text += line;
        text += "\n";
    }
    qDebug() << QString::fromStdString(text);


    input.close();
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
//    setAttribute(Qt::WA_TranslucentBackground);
    auto shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0);
    shadow_effect->setColor(QColor(0,0,0));
    shadow_effect->setBlurRadius(15);
    setGraphicsEffect(shadow_effect);

    // UI
    ui->recommend->initContent(":/resources/images/icon/rec.png", "推荐", 0);
    ui->radio->initContent(":/resources/images/icon/radio.png", "电台", 1);
    ui->explore->initContent(":/resources/images/icon/music.png", "探索", 2);
    ui->myLove->initContent(":/resources/images/icon/like.png", "我喜欢", 3);
    ui->recent->initContent(":/resources/images/icon/recent.png", "最近播放", 4);
    ui->local->initContent(":/resources/images/icon/local.png", "本地下载", 5);
}

void MainWindow::initConnect()
{
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

