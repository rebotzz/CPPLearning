#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto form = new Form(ui->tab_2);
    auto layout_tab = ui->centralwidget->layout();
    layout_tab->addWidget(form);
}

MainWindow::~MainWindow()
{
    delete ui;
}

