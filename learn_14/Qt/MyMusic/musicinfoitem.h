#ifndef MUSICINFOITEM_H
#define MUSICINFOITEM_H

#include <QWidget>
#include <QString>

namespace Ui {
class MusicInfoItem;
}

class MusicInfoItem : public QWidget
{
    Q_OBJECT

public:
    explicit MusicInfoItem(QWidget *parent, const QString& path, const QString& music_name,
                           const QString& singer, const QString& album);
    ~MusicInfoItem();

    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void onFavorBtnClick();

    void setFavor(bool flag) { is_favor = flag; }
    bool getFavor() const { return is_favor; }
    void setFavorIcon();

private:
    Ui::MusicInfoItem *ui;
    bool is_favor = false;
    QString path;
};

#endif // MUSICINFOITEM_H
