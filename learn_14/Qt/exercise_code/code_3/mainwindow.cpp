#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QPushButton>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton* btn1 = new QPushButton("按钮1");
    QPushButton* btn2 = new QPushButton("按钮2");
    QPushButton* btn3 = new QPushButton("按钮3");
    // 创建布局管理器, 并且把按钮添加进去
    // 如果创建的时候指定⽗元素为 this, 则后⾯不需要 setLayout ⽅法了.
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    // 把布局管理器设置到 widget 中
    this->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

