/** @file instruction.cpp
    @author [Adrienne Mok]
    @date [June 3, 2016]

    [Defines function for instruction page]

*/


#include "instruction.h"
#include "ui_instruction.h"

/** Instruction Constructor
    @param parent is a pointer to some QWidget
*/
Instruction::Instruction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Instruction)
{
    ui->setupUi(this);

    // Instructions Page
    QVBoxLayout* helpLayout = new QVBoxLayout;
    QLabel* helpTitle = new QLabel("<center>Instructions</center>");
    QFont title = helpTitle->font();
    title.setPointSize(60);
    helpTitle->setFont(title);
    QLabel* minion2 = new QLabel;
    QPixmap instructionPixmap(":/images/minion2.png");
    QPixmap p2(instructionPixmap.scaled(500,500,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    minion2->setPixmap(p2);
    minion2->setMask(p2.mask());
    minion2->setFixedHeight(p2.height());
    minion2->setFixedWidth(p2.width());
    QLabel* words = new QLabel("<center>Hit the minion by clicking your mouse within a reasonable amount of time.<center>");
    QFont wordsfont = words->font();
    wordsfont.setPointSize(16);
    words->setFont(wordsfont);

    // Quit to Main Menu
    QHBoxLayout* returnToMenulayout = new QHBoxLayout;
    QPushButton* returnToMenu = new QPushButton("MENU");
    QFont instructionfont = returnToMenu->font();
    instructionfont.setPointSize(20);
    returnToMenu->setFont(instructionfont);
    returnToMenu->setFixedWidth(150);
    returnToMenu->setFixedHeight(50);
    returnToMenulayout->addSpacing(300);
    returnToMenulayout->addWidget(returnToMenu);
    returnToMenulayout->addSpacing(300);
    QObject::connect(returnToMenu,SIGNAL(clicked()),this,SLOT(hide()));

    // Put whole Instructions Page interface together
    helpLayout->addSpacing(50);
    helpLayout->addWidget(helpTitle);
    QHBoxLayout* helppic = new QHBoxLayout;
    helppic->addSpacing(100);
    helppic->addWidget(minion2);
    helppic->addSpacing(100);
    helpLayout->addSpacing(40);
    helpLayout->addLayout(helppic);
    helpLayout->addSpacing(30);
    helpLayout->addWidget(words);
    helpLayout->addLayout(returnToMenulayout);
    helpLayout->addSpacing(70);
    this->setLayout(helpLayout);
    this->setWindowState(Qt::WindowFullScreen);

}

/** Instruction Destructor
*/
Instruction::~Instruction()
{
    delete ui;
}
