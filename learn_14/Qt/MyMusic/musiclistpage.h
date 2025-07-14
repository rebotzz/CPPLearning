#ifndef MUSICLISTPAGE_H
#define MUSICLISTPAGE_H

#include <QWidget>

namespace Ui {
class MusicListPage;
}

class MusicListPage : public QWidget
{
    Q_OBJECT

public:
    explicit MusicListPage(QWidget *parent = nullptr);
    ~MusicListPage();

private:
    Ui::MusicListPage *ui;
};

#endif // MUSICLISTPAGE_H
