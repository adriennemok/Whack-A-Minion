/********************************************************************************
** Form generated from reading UI file 'lives.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIVES_H
#define UI_LIVES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lives
{
public:

    void setupUi(QWidget *Lives)
    {
        if (Lives->objectName().isEmpty())
            Lives->setObjectName(QStringLiteral("Lives"));
        Lives->resize(400, 300);

        retranslateUi(Lives);

        QMetaObject::connectSlotsByName(Lives);
    } // setupUi

    void retranslateUi(QWidget *Lives)
    {
        Lives->setWindowTitle(QApplication::translate("Lives", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Lives: public Ui_Lives {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIVES_H
