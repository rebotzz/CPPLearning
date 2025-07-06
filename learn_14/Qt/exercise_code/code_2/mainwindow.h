#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent* event) override;
//    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonDel_clicked();

    void on_pushButtonAddRow_clicked();

    void on_pushButtonDelRow_clicked();

    void on_pushButtonAddCol_clicked();

    void on_pushButtonDelCol_clicked();

    void on_pushButtonAddTab_clicked();

    void on_pushButtonDelTab_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
