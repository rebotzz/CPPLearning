#ifndef MUSICLISTPAGE_H
#define MUSICLISTPAGE_H

#include <QWidget>
#include <QString>
#include <QJsonObject>

#include <vector>
#include <string>

namespace Ui {
class MusicListPage;
}

class MusicListPage : public QWidget
{
    Q_OBJECT

public:
    explicit MusicListPage(QWidget *parent = nullptr);
    ~MusicListPage();

    void loadMusicList(const std::string& config_path);


private:
    Ui::MusicListPage *ui;
};

#endif // MUSICLISTPAGE_H
