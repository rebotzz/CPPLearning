#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
//#include <QCloseEvent>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void closeEvent(QCloseEvent* event) override;

private slots:
    void openFile();
    void saveFile();
    void saveAsOther();
    void Quit();

private:
    void _saveFile();
    void initWindow();
    void initFileMenu();

private:
    Ui::MainWindow *ui;
    bool is_saved = false;
    std::string file_path;
};
#endif // MAINWINDOW_H
