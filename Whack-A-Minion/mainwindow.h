/** @file mainwindow.h
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Creates MainWindow]

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "game.h"
#include "instruction.h"
#include <QApplication>
#include <QPalette>
#include <QPixmap>
#include <QResizeEvent>
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QBitmap>
#include <QFont>

// Forward declaration
namespace Ui {
class MainWindow;
}

/** @class MainWindow
    @brief Creates a MainWindow for Whack-A-Minion! GUI

    This class creates a MainWindow for the Whack-A-Minion! GUI
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void play();
    void instruct();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
