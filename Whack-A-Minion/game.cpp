/** @file game.cpp
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Defines function for interface of game]

*/


#include "game.h"
#include "ui_game.h"


/** Game Constructor
    @param parent is a pointer to some QWidget
*/
Game::Game(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Game),
    remaining_lives(3)
{
    ui->setupUi(this);

    // Gameplay
    QHBoxLayout* lives = new QHBoxLayout;
    QVBoxLayout* left = new QVBoxLayout;
    QHBoxLayout* backtoMenulayout = new QHBoxLayout;
    QPushButton* backtoMenu = new QPushButton("MENU");
    QFont menufont = backtoMenu->font();
    menufont.setPointSize(20);
    backtoMenu->setFont(menufont);
    backtoMenu->setFixedWidth(150);
    backtoMenu->setFixedHeight(50);
    backtoMenulayout->addWidget(backtoMenu);

    // Display number of lives left
    QPixmap heartPixmap(":/images/heart.png");
    QPixmap heart2(heartPixmap.scaled(100,100,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    life1->setPixmap(heart2);
    life1->setMask(heart2.mask());
    life1->setFixedHeight(heart2.height());
    life1->setFixedWidth(heart2.width());
    life2->setPixmap(heart2);
    life2->setMask(heart2.mask());
    life2->setFixedHeight(heart2.height());
    life2->setFixedWidth(heart2.width());
    life3->setPixmap(heart2);
    life3->setMask(heart2.mask());
    life3->setFixedHeight(heart2.height());
    life3->setFixedWidth(heart2.width());
    lives->addWidget(life1);
    lives->addWidget(life2);
    lives->addWidget(life3);
    left->addLayout(lives);
    left->addWidget(backtoMenu);
    QObject::connect(backtoMenu,SIGNAL(clicked()),this,SLOT(leave_game()));

    // Number of Minions hit
    QVBoxLayout* right = new QVBoxLayout;
    QFont rightfont = hitscore->font();
    rightfont.setPointSize(36);
    hitscore->setFont(rightfont);
    hitscore->setText(QString("HIT: ") + QString::number(points->get_score()));
    right->addWidget(hitscore);
    right->addSpacing(100);
    QHBoxLayout* icons = new QHBoxLayout;
    icons->addLayout(left);
    icons->addSpacing(1100);
    icons->addLayout(right);
    QVBoxLayout* overall = new QVBoxLayout;
    overall->addLayout(icons);

    // Creates 3 rows of holes
    for(int i=0;i<3;i++){
        QHBoxLayout* hlayout = new QHBoxLayout;

        // Creates 3 columns of holes
        for(int j=0;j<3;j++) {
            mole[i+3*j];
            mole[i+3*j].setFixedHeight(300);
            mole[i+3*j].setFixedWidth(300);
            QRegion* region = new QRegion(*(new QRect(mole[i+3*j].x()+5,mole[i+3*j].y()+5,290,290)),QRegion::Ellipse);
            mole[i+3*j].setMask(*region);
            hlayout->addWidget(&mole[i+3*j]);
        }

        overall->addLayout(hlayout);
    }

    this->setLayout(overall);

    this->setWindowState(Qt::WindowFullScreen);
    target_hole = minion_hole();

    connect(timer, SIGNAL(timeout()),this, SLOT(check()));
    timer->start(3000);
    mole[target_hole].setStyleSheet("QPushButton{background-image: url(:/images/jumpingminion.png); background-repeat:no-repeat; background-position: center center}");

    connect(&mole[target_hole], SIGNAL(clicked()), this, SLOT(hit()));

}

/** Game Destructor
*/
Game::~Game()
{
    delete ui;
}

/** Select minion to pop out of hole

    @return the number of the hole that the mole will pop out of
*/
int Game::minion_hole()
{
    qsrand(time(NULL));

    return (qrand() % (10));
}

/** Raise score if user hits button
*/
void Game::hit()
{
    timer->stop();
    mole[target_hole].setStyleSheet("QPushButton{background: lightgrey;}");
    points->raise_score();
    hitscore->setText(QString("HIT: ") + QString::number(points->get_score()));
    target_hole = minion_hole();
    mole[target_hole].setStyleSheet("QPushButton{background-image: url(:/images/jumpingminion.png); background-repeat:no-repeat; background-position: center center}");
    timer->start(3000);
    connect(&mole[target_hole], SIGNAL(clicked()), this, SLOT(hit()));

    return;
}

/** Check to see if user hit button in time
*/
void Game::check()
{
    // check if button pressed in time
    if (remaining_lives > 0)
    {
        mole[target_hole].setStyleSheet("QPushButton{background: lightgrey;}");
        --remaining_lives;

        // Now 2 hearts
        if (remaining_lives == 2)
        {
            life3->hide();
        }

        // Now 1 life left
        else if(remaining_lives == 1)
        {
            life2->hide();
        }

        // No lives left
        else // remaining_lives == 0
        {
            life1->hide();
        }
        target_hole = minion_hole();
        mole[target_hole].setStyleSheet("QPushButton{background-image: url(:/images/jumpingminion.png); background-repeat:no-repeat; background-position: center center}");
        connect(&mole[target_hole], SIGNAL(clicked()), this, SLOT(hit()));

        timer->start(3000);

    }

    // No more lives yet
    else
    {
        timer->stop();
        QWidget* die = new QWidget;


        QVBoxLayout* overall = new QVBoxLayout;
        QLabel* end = new QLabel("<center>GAME OVER</center>");
        QFont font = end->font();
        font.setPointSize(100);
        font.setBold(true);
        end->setFont(font);
        QLabel* minion = new QLabel;
        QPixmap instructionPixmap(":/images/bye.png");
        QPixmap p2(instructionPixmap.scaled(500,500,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        minion->setPixmap(p2);
        minion->setMask(p2.mask());
        minion->setFixedHeight(p2.height());
        minion->setFixedWidth(p2.width());

        // Quit to Main Menu
        QHBoxLayout* returnToMenulayout = new QHBoxLayout;
        QPushButton* returnToMenu = new QPushButton("MENU");
        QFont menufont = returnToMenu->font();
        menufont.setPointSize(20);
        returnToMenu->setFont(menufont);
        returnToMenu->setFixedWidth(150);
        returnToMenu->setFixedHeight(50);
        returnToMenulayout->addSpacing(300);
        returnToMenulayout->addWidget(returnToMenu);
        returnToMenulayout->addSpacing(300);

        // Put whole interface together
        overall->addSpacing(200);
        overall->addWidget(end);
        QHBoxLayout* pic = new QHBoxLayout;
        overall->addSpacing(100);
        pic->addWidget(minion);
        overall->addLayout(pic);
        overall->addSpacing(200);
        overall->addLayout(returnToMenulayout);
        overall->addSpacing(100);
        die->setLayout(overall);
        die->setWindowState(Qt::WindowFullScreen);
        QObject::connect(returnToMenu,SIGNAL(clicked()),this,SLOT(close()));
        QObject::connect(returnToMenu,SIGNAL(clicked()),die,SLOT(close()));
        die->show();

    }

}

/** Exit Back to Main Menu
*/
void Game::leave_game()
{
    timer->stop();
    hide();

    return;
}





