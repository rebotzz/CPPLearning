#include "myfiledialog.h"
#include <QDebug>


MyFileDialog::MyFileDialog(QWidget *parent):QFileDialog(parent)
{

}

MyFileDialog::~MyFileDialog()
{
    qDebug() << "~MyFileDialog()";
}
