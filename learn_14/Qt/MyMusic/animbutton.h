#ifndef AnimButton_H
#define AnimButton_H

#include <QWidget>

namespace Ui {
class AnimButton;
}
class QPropertyAnimation;
class QLabel;

class AnimButton : public QWidget
{
    Q_OBJECT

public:
    explicit AnimButton(QWidget *parent = nullptr);
    ~AnimButton();


    void resetStyleSheet();
    void showAnimation();
    void hideAnimation();

    void initContent(QString icon, QString text, int pageId);
    int getPageId() const { return m_pageId; }

signals:
   void click(int pageId);

protected:
   void mousePressEvent(QMouseEvent* event) override;

private:
   void initAnimation(QLabel* line, int duration_ms, QRect start, QRect mid, QRect end);

private:
    Ui::AnimButton *ui;
    int m_pageId = 0;
    QPropertyAnimation* animLine1;
    QPropertyAnimation* animLine2;
    QPropertyAnimation* animLine3;
    QPropertyAnimation* animLine4;
};

#endif // AnimButton_H
