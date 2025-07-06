#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGridLayout>
#include <QString>
#include <QDebug>
#include <fstream>
#include <memory>


// 测试表明：tableWidget->removeRow 会调用析构函数，释放空间
class MyQTableWidgetItem : public QTableWidgetItem
{
public:
    MyQTableWidgetItem(const char* str):QTableWidgetItem(str)
    {}
    ~MyQTableWidgetItem()
    {
        qDebug() << "~MyQTabelWidgetItem()";
    }
};

// 测试表明：listWidget->takeItem 不会释放内存，需要手动释放
struct MyQListWidgetItem : public QListWidgetItem
{
    MyQListWidgetItem(const char* str):QListWidgetItem(str)
    {

    }
    ~MyQListWidgetItem()
    {
        qDebug() << "~MyQListWidgetItem()";
    }
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // listWidget
    connect(ui->listWidget, &QListWidget::currentItemChanged, this,
                  [=](QListWidgetItem *current, QListWidgetItem *previous)
    {
        if(!current || !previous) return;
        qDebug() << QString("previous: ") + previous->text() + " current: " + current->text();
    });
    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("C#");
    ui->listWidget->addItem(new MyQListWidgetItem("Python"));

    // file + combo_box
    auto close_file = [](std::ifstream* file){
        if(file && file->is_open())
        {
            file->close();
            qDebug() << "close file";
        }
    };
    auto input_file = std::ifstream("../res/name_list.txt");
    auto file_ptr = std::unique_ptr<std::ifstream, decltype(close_file)>(&input_file, close_file);
    std::string line;
    while(std::getline(*(file_ptr.get()), line))
    {
        ui->comboBox->addItem(QString::fromStdString(line));
    }

    auto layout = new QGridLayout(this);
    layout->addWidget(ui->tabWidget);
    setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
//    auto rect_window = rect();
//    auto rect_grid = ui->gridLayout->geometry();
//    auto rect_new = QRect(rect_grid.x(), rect_grid.y(),
//                          rect_window.width() - rect_grid.x(), rect_window.height() - rect_grid.y());
//    ui->gridLayout->setGeometry(rect_new);
//    ui->verticalLayout->setGeometry(rect_window);
}


void MainWindow::on_pushButtonAdd_clicked()
{
    QString text = ui->lineEditList->text();
    if(text.isEmpty()) return;

    ui->listWidget->addItem(text);
    ui->lineEditList->setText("");
}


void MainWindow::on_pushButtonDel_clicked()
{
    if(ui->listWidget->count() == 0) return;
    int current_row = ui->listWidget->currentRow();
    int remove_row = ui->listWidget->count() - 1;
    if(current_row >= 0 && current_row < ui->listWidget->count()) remove_row = current_row;
    qDebug() << QString("del row: ") + QString::number(remove_row);
    // 测试表明：listWidget->takeItem 不会释放内存，需要手动释放
    auto item = ui->listWidget->takeItem(remove_row);
    delete item;
}


void MainWindow::on_pushButtonAddRow_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new MyQTableWidgetItem("hello"));
}

void MainWindow::on_pushButtonDelRow_clicked()
{
    // 测试表明：会调用析构函数，释放空间
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

void MainWindow::on_pushButtonAddCol_clicked()
{
    auto& table = ui->tableWidget;
    if(ui->lineEditTable->text().isEmpty()) return;
    int col_idx = table->columnCount();
    table->insertColumn(col_idx);
    table->setHorizontalHeaderItem(col_idx, new QTableWidgetItem(ui->lineEditTable->text()));
    ui->lineEditTable->setText("");
}

void MainWindow::on_pushButtonDelCol_clicked()
{
    ui->tableWidget->removeColumn(ui->tableWidget->currentColumn());
}

void MainWindow::on_pushButtonAddTab_clicked()
{
    auto widget = new QWidget;
    auto label = new QLabel(widget);
    label->setText(QString("Tab_Label") + QString::number(ui->tabWidget->count() + 1));
    ui->tabWidget->addTab(widget, QString("Tab") + QString::number(ui->tabWidget->count() + 1));
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count());
}

void MainWindow::on_pushButtonDelTab_clicked()
{
    int cur_idx = ui->tabWidget->currentIndex();
//    int cnt = ui->tabWidget->count();
    ui->tabWidget->removeTab(cur_idx);
}
