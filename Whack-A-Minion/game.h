/** @file game.h
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Declares functions for interface of game]

*/


#ifndef GAME_H
#define GAME_H

#include <QWidget>

#include "mainwindow.h"
#include "score.h"
#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QBitmap>
#include <QTime>
#include <ctime>
#include <iostream>
#include <QTimer>
#include <QString>
#include <QFont>

namespace Ui {
class Game;
}

/** @class Game
    @brief Creates the interface for the game

    This class creates a user interface for the Whack-A-Minion game
*/
class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();
    int minion_hole();

public slots:
    void hit();
    void check();
    void leave_game();

private:
    Ui::Game *ui;
    QLabel* life1 = new QLabel;
    QLabel* life2 = new QLabel;
    QLabel* life3 = new QLabel;
    QLabel* hitscore = new QLabel;
    int remaining_lives;
    int target_hole;
    score* points = new score(this);
    QTimer* timer = new QTimer();
    QPushButton* mole = new QPushButton[9];
};

#endif // GAME_H
