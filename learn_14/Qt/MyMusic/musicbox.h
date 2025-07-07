#ifndef RECBOXITEM_H
#define RECBOXITEM_H

#include <QWidget>

namespace Ui {
class MusicBox;
}

class MusicBox : public QWidget
{
    Q_OBJECT

public:
    explicit MusicBox(QWidget *parent = nullptr);
    ~MusicBox();

private:
    Ui::MusicBox *ui;
};

#endif // RECBOXITEM_H
