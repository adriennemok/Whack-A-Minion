/** @file score.cpp
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Defines functions for score tracker]

*/


#include "score.h"
#include "ui_score.h"
#include <QString>
#include <QFont>

/** Score Constructor
    @param parent is a pointer to some QWidget)
*/
score::score(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::score),
    player_score(0)
{
    ui->setupUi(this);
}

/** Score Destructor
*/
score::~score()
{
    delete ui;
}

/** Give player's score
 *
    @return player's score
*/
int score::get_score()
{
    return player_score;
}

/** Increase player's score
*/
void score::raise_score()
{
    ++player_score;

    return;
}

/** Reset player's score
*/
void score::reset_score()
{
    player_score = 0;

    return;
}



