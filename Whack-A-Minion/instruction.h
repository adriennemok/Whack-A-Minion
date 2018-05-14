/** @file instruction.h
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Declares functions for instructions interface]

*/


#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QWidget>

#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QBitmap>
#include <QFont>

namespace Ui {
class Instruction;
}

/** @class Instruction
    @brief Creates a Instruction page

    This class creates an instruction page for the user
*/
class Instruction : public QWidget
{
    Q_OBJECT

public:
    explicit Instruction(QWidget *parent = 0);
    ~Instruction();

private:
    Ui::Instruction *ui;
};

#endif // INSTRUCTION_H
