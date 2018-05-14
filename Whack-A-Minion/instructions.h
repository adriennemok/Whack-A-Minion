#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QWidget>

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QBitmap>


namespace Ui {
class Instructions;
}

class Instructions : public QWidget
{
    Q_OBJECT

public:
    explicit Instructions(QWidget *parent = 0);
    ~Instructions();

private:
    Ui::Instructions *ui;
};

#endif // INSTRUCTIONS_H
