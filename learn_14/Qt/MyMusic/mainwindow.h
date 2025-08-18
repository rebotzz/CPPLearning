#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QPoint>
#include <QVector2D>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initMusicBoxList();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

// 现在似乎不用假slots都行
private slots:
    void on_buttonQuit_clicked();
    void onBtFormClick(int pageId);

    void on_buttonMin_clicked();

    void on_buttonMax_clicked();

    void on_buttonSkin_clicked();

private:
    void initWindow();
    void initConnect();

private:
    Ui::MainWindow *ui;
    QPoint dragPosition;   // 鼠标拖动窗口是相对于窗口坐标
    bool is_maxshow = false;
};
#endif // MAINWINDOW_H
