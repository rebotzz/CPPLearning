#ifndef MYFILEDIALOG_H
#define MYFILEDIALOG_H
#include <QFileDialog>

class MyFileDialog : public QFileDialog
{
public:
    MyFileDialog(QWidget* parent);
    ~MyFileDialog();
};

#endif // MYFILEDIALOG_H
