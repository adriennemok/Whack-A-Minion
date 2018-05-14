/********************************************************************************
** Form generated from reading UI file 'game_over.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_OVER_H
#define UI_GAME_OVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_game_over
{
public:

    void setupUi(QWidget *game_over)
    {
        if (game_over->objectName().isEmpty())
            game_over->setObjectName(QStringLiteral("game_over"));
        game_over->resize(400, 300);

        retranslateUi(game_over);

        QMetaObject::connectSlotsByName(game_over);
    } // setupUi

    void retranslateUi(QWidget *game_over)
    {
        game_over->setWindowTitle(QApplication::translate("game_over", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class game_over: public Ui_game_over {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_OVER_H
