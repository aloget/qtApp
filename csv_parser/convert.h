#ifndef CONVERT_H
#define CONVERT_H

#include <QDialog>

namespace Ui {
class convert;
}

class convert : public QDialog
{
    Q_OBJECT

public:
    explicit convert(QWidget *parent = 0);
    ~convert();

private:
    Ui::convert *ui;
};

#endif // CONVERT_H
