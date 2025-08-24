#ifndef VOLUMETOOL_H
#define VOLUMETOOL_H

#include <QWidget>

namespace Ui {
class VolumeTool;
}

class VolumeTool : public QWidget
{
    Q_OBJECT

public:
    explicit VolumeTool(QWidget *parent = nullptr);
    ~VolumeTool();
    virtual void paintEvent(QPaintEvent* event) override;

    void initConnect();

    void onSliderMoved(int val);

private:
    Ui::VolumeTool *ui;
};

#endif // VOLUMETOOL_H
