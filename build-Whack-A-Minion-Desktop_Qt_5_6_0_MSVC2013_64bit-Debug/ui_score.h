/********************************************************************************
** Form generated from reading UI file 'score.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORE_H
#define UI_SCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_score
{
public:

    void setupUi(QWidget *score)
    {
        if (score->objectName().isEmpty())
            score->setObjectName(QStringLiteral("score"));
        score->resize(400, 300);

        retranslateUi(score);

        QMetaObject::connectSlotsByName(score);
    } // setupUi

    void retranslateUi(QWidget *score)
    {
        score->setWindowTitle(QApplication::translate("score", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class score: public Ui_score {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORE_H
