/** @file score.h
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Declares interface for score tracker]

*/


#ifndef SCORE_H
#define SCORE_H

#include <QWidget>
#include <QString>

namespace Ui {
class score;
}

/** @class score
    @brief Keeps track of the score for Whack-A-Minion

    Keeps track of the player's score
*/
class score : public QWidget
{
    Q_OBJECT

public:
    explicit score(QWidget *parent = 0);
    ~score();
    int get_score();
    void raise_score();
    void reset_score();

private:
    Ui::score *ui;
    int player_score;
};

#endif // SCORE_H
