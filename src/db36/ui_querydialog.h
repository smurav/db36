/********************************************************************************
** Form generated from reading UI file 'querydialog.ui'
**
** Created: Thu Sep 27 14:50:21 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYDIALOG_H
#define UI_QUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_QueryDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QLineEdit *sql_query;
    QLabel *label;

    void setupUi(QDialog *QueryDialog)
    {
        if (QueryDialog->objectName().isEmpty())
            QueryDialog->setObjectName(QString::fromUtf8("QueryDialog"));
        QueryDialog->resize(812, 76);
        gridLayout = new QGridLayout(QueryDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(QueryDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 1, 1, 1);

        sql_query = new QLineEdit(QueryDialog);
        sql_query->setObjectName(QString::fromUtf8("sql_query"));

        gridLayout->addWidget(sql_query, 0, 1, 1, 1);

        label = new QLabel(QueryDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(QueryDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QueryDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QueryDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(QueryDialog);
    } // setupUi

    void retranslateUi(QDialog *QueryDialog)
    {
        QueryDialog->setWindowTitle(QApplication::translate("QueryDialog", "SQL", 0, QApplication::UnicodeUTF8));
        sql_query->setText(QApplication::translate("QueryDialog", "SELECT * FROM tablename;", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("QueryDialog", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QueryDialog: public Ui_QueryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYDIALOG_H
