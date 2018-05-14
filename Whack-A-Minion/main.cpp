/** @mainpage main.cpp
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Creates a GUI for Whack-A-Minion!]
*/

#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QBitmap>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}
