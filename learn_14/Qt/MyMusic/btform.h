#ifndef BTFORM_H
#define BTFORM_H

#include <QWidget>

namespace Ui {
class BtForm;
}
class QPropertyAnimation;
class QLabel;

class BtForm : public QWidget
{
    Q_OBJECT

public:
    explicit BtForm(QWidget *parent = nullptr);
    ~BtForm();


    void resetStyleSheet();
    void showAnimation();
    void hideAnimation();

    void setContent(QString icon, QString text, int pageId);
    int getPageId() const { return m_pageId; }

signals:
   void click(int pageId);

protected:
   void mousePressEvent(QMouseEvent* event) override;

private:
   void initAnimation(QLabel* line, int duration_ms, QRect start, QRect mid, QRect end);

private:
    Ui::BtForm *ui;
    int m_pageId = 0;
    QPropertyAnimation* animLine1;
    QPropertyAnimation* animLine2;
    QPropertyAnimation* animLine3;
    QPropertyAnimation* animLine4;
};

#endif // BTFORM_H
