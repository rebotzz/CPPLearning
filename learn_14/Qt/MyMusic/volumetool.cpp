#include "volumetool.h"
#include "ui_volumetool.h"

#include <QGraphicsDropShadowEffect>
#include <QPainter>

VolumeTool::VolumeTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VolumeTool)
{
    ui->setupUi(this);

    // 在windows上，设置透明效果后，窗口需要加上Qt::FramelessWindowHint格式
    // 否则没有控件位置的背景是黑色的
    // 由于默认窗口有阴影，因此还需要将窗口的原有的阴影去掉，窗口需要加上Qt::NoDropShadowWindowHint
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // 阴影效果
    auto shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset({0,0});
    shadow_effect->setColor("#646464");
    shadow_effect->setBlurRadius(10);
    setGraphicsEffect(shadow_effect);

    // 默认音量设置
    ui->slider->setValue(20);
    ui->volume_label->setText("20%");


    // 初始化信号与槽
    initConnect();
}

VolumeTool::~VolumeTool()
{
    delete ui;
}

void VolumeTool::paintEvent(QPaintEvent *)
{
    // 1.创建画家
    // 2.设置抗锯齿
    // 3.设置画笔
    // 4.设置笔刷颜色
    // 5.绘制

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::NoPen);  //没有画笔时：画出来的图形就没有边框和轮廓线
    painter.setBrush(Qt::white);
    QPolygon polygon;
    auto w = ui->volume_widget->width();
    auto h = ui->volume_widget->height();
    auto bottom = height() - 10;
    polygon.append(QPoint(w / 2 - 20, h));
    polygon.append(QPoint(w / 2 + 20, h));
    polygon.append(QPoint(w / 2, bottom));
    painter.drawPolygon(polygon);
}

void VolumeTool::initConnect()
{
    connect(ui->slider, &QSlider::valueChanged, this, &VolumeTool::onSliderMoved);
}

void VolumeTool::onSliderMoved(int val)
{
//    int val = ui->slider->value();
    ui->volume_label->setText(QString::fromStdString(std::to_string(val) + "%"));
    // TODO:设置音量

}






















