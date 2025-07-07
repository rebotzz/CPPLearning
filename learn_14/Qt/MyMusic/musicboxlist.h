#ifndef MusicBoxList_H
#define MusicBoxList_H

#include <QWidget>

namespace Ui {
class MusicBoxList;
}

class MusicBoxList : public QWidget
{
    Q_OBJECT

public:
    explicit MusicBoxList(QWidget *parent = nullptr);
    ~MusicBoxList();

private:
    Ui::MusicBoxList *ui;
};

#endif // MusicBoxList_H
