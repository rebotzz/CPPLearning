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

    void setText(const QString& text);
    void setImage(const QString& path);

private:
    bool eventFilter(QObject* watched, QEvent* event) override;

private:
    Ui::MusicBox *ui;
};

#endif // RECBOXITEM_H
