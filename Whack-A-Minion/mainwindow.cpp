/** @file mainwindow.cpp
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Defines functions from "mainwindow.h"]

*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

/** Constructor for MainWindow (OR MAIN MENU)
    @param parent is a pointer to some QWidget
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Whack-A-Minion!");

    // Main Menu
    QWidget* window = new QWidget;
    QLabel* title = new QLabel("<center><b>Whack-A-Minion!</b></center>");
    QFont titlefont = title->font();
    titlefont.setPointSize(75);
    title->setFont(titlefont);
    QVBoxLayout* menu = new QVBoxLayout;

    // Main Menu Artwork
    QLabel* minion = new QLabel;
    QPixmap pixmap(":/images/minion1.png");
    QPixmap p1(pixmap.scaled(800,800,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    minion->setPixmap(p1);
    minion->setMask(p1.mask());
    minion->setFixedHeight(p1.height());
    minion->setFixedWidth(p1.width());

    // Start Game
    QHBoxLayout* startlayout = new QHBoxLayout;
    QPushButton* start = new QPushButton("START");
    QFont startfont = start->font();
    startfont.setPointSize(15);
    start->setFont(startfont);
    start->setFixedWidth(175);
    start->setFixedHeight(50);
    startlayout->addSpacing(300);
    startlayout->addWidget(start);
    startlayout->addSpacing(300);

    //  Prompt for Instructions
    QHBoxLayout* helplayout = new QHBoxLayout;
    QPushButton* help = new QPushButton("INSTRUCTIONS");
    QFont helpfont = help->font();
    helpfont.setPointSize(15);
    help->setFont(helpfont);
    help->setFixedWidth(175);
    help->setFixedHeight(50);
    helplayout->addSpacing(300);
    helplayout->addWidget(help);
    helplayout->addSpacing(300);

    // Quit Game
    QHBoxLayout* quitlayout = new QHBoxLayout;
    QPushButton* quit = new QPushButton("QUIT");
    QFont quitfont = quit->font();
    quitfont.setPointSize(15);
    quit->setFont(quitfont);
    quit->setFixedWidth(175);
    quit->setFixedHeight(50);
    quitlayout->addSpacing(300);
    quitlayout->addWidget(quit);
    quitlayout->addSpacing(300);

    // Put whole Main Menu interface together
    menu->addSpacing(30);
    menu->addWidget(title);
    QHBoxLayout* pic = new QHBoxLayout;
    pic->addSpacing(100);
    pic->addWidget(minion);
    pic->addSpacing(100);
    menu->addLayout(pic);
    menu->addSpacing(15);;
    menu->addLayout(startlayout);
    menu->addLayout(helplayout);
    menu->addLayout(quitlayout);
    window->setLayout(menu);
    this->setCentralWidget(window);
    this->setWindowState(Qt::WindowFullScreen);

    // Connect all the buttons together
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(play()));
    QObject::connect(help,SIGNAL(clicked()),this,SLOT(instruct()));
    QObject::connect(quit,SIGNAL(clicked()),this,SLOT(close()));
}

/** Destructor for MainWindow
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/** Begins game
*/
void MainWindow::play()
{
    Game* game = new Game();
    game->show();
}

/** Opens Instruction Page
*/
void MainWindow::instruct()
{
    Instruction* instruction_page = new Instruction();
    instruction_page->show();
}


