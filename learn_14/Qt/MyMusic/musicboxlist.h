#ifndef MusicBoxList_H
#define MusicBoxList_H

#include <QWidget>
#include <unordered_map>
#include <vector>
#include <array>

namespace Ui {
class MusicBoxList;
}

class MusicBoxList : public QWidget
{
    Q_OBJECT

public:
    explicit MusicBoxList(QWidget *parent = nullptr);
    ~MusicBoxList();

    void loadMusic(const std::vector<QJsonObject>& musicList);
    void refresh();
    void setOnlyUpLine(bool flag) { onlyUpLine = flag; }
    void clearMusicBox();
    void clearLayout(QLayout* layout);

private slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();

private:
    Ui::MusicBoxList *ui;
    bool onlyUpLine = false;
    int lineMusicCount = 4;
    int currentIdx = 0;
    std::vector<QJsonObject> m_musicList;
};


#endif // MusicBoxList_H
