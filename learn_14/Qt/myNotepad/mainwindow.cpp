#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QAction>
#include <QDebug>
#include <fstream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initWindow();
    initFileMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    Quit();
}

void MainWindow::openFile()
{
    auto file_dialog = new QFileDialog(this);
    file_dialog->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    auto path = file_dialog->getOpenFileName();
    if(path.isEmpty()) return;
    auto input = std::ifstream(path.toStdString());
    if(input.fail()) return;
    file_path = path.toStdString();
    std::string line, text;
    while(std::getline(input, line))
    {
        text += line;
        text += "\n";
    }
    input.close();
    ui->textEditor->setText(QString::fromStdString(text));
}

void MainWindow::saveFile()
{
    if(file_path.empty())
    {
        saveAsOther();
    }
    else
    {
       _saveFile();
    }
}

void MainWindow::saveAsOther()
{
    auto file_dialog = new QFileDialog(this);
    file_dialog->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
    auto path = file_dialog->getSaveFileName(this, "保存文件", ".", "文件类型 (*.txt)");
    if(path.isEmpty()) return;
    file_path = path.toStdString();
    _saveFile();
}

void MainWindow::Quit()
{
    if(!is_saved && (!file_path.empty() || !ui->textEditor->toPlainText().isEmpty()))
    {
        auto save_dialog = new QMessageBox(QMessageBox::Warning, "注意", "文件未保存，是否需要保存？",
                                           QMessageBox::Discard | QMessageBox::Save, this);
        save_dialog->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose);
        if(QMessageBox::Save == save_dialog->exec())
        {
            saveFile();
        }
        exit(0);
    }
}

void MainWindow::_saveFile()
{
    auto output = std::ofstream(file_path, std::ios::trunc);
     std::string text = ui->textEditor->toPlainText().toStdString();
     output << text;
     output.close();
}

void MainWindow::initWindow()
{
    setWindowTitle("My Notepad");
    setWindowIcon(QIcon(":/logo.ico"));
}

void MainWindow::initFileMenu()
{
    // 文件菜单
    auto file = new QMenu("文件");
    auto open = new QAction("打开", this);
    auto save = new QAction("保存", this);
    auto save_as_other = new QAction("另存为", this);
    auto quit = new QAction("退出", this);
    open->setShortcut(QKeySequence("Ctrl+N"));
    save->setShortcut(QKeySequence("Ctrl+S"));
    save_as_other->setShortcut(QKeySequence("Ctrl+Shift+S"));
    quit->setShortcut(QKeySequence("Ctrl+Q"));

    connect(open, &QAction::triggered, this, &MainWindow::openFile);
    connect(save, &QAction::triggered, this, &MainWindow::saveFile);
    connect(save_as_other, &QAction::triggered, this, &MainWindow::saveAsOther);
    connect(quit, &QAction::triggered, this, &MainWindow::Quit);
    file->addAction(open);
    file->addAction(save);
    file->addAction(save_as_other);
    file->addAction(quit);
    ui->menubar->addMenu(file);

    // init textEditor
    connect(ui->textEditor, &QTextEdit::textChanged, this, [&]()
    {
        is_saved = false;
    });
}

