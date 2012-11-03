/********************************************************************************
** Form generated from reading UI file 'progressbar.ui'
**
** Created: Thu Oct 11 22:52:29 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBAR_H
#define UI_PROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProgressBar
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QProgressBar *progress_bar_;

    void setupUi(QDialog *ProgressBar)
    {
        if (ProgressBar->objectName().isEmpty())
            ProgressBar->setObjectName(QString::fromUtf8("ProgressBar"));
        ProgressBar->resize(423, 71);
        formLayout = new QFormLayout(ProgressBar);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ProgressBar);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        progress_bar_ = new QProgressBar(ProgressBar);
        progress_bar_->setObjectName(QString::fromUtf8("progress_bar_"));
        progress_bar_->setValue(0);

        verticalLayout->addWidget(progress_bar_);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);


        retranslateUi(ProgressBar);

        QMetaObject::connectSlotsByName(ProgressBar);
    } // setupUi

    void retranslateUi(QDialog *ProgressBar)
    {
        ProgressBar->setWindowTitle(QApplication::translate("ProgressBar", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ProgressBar", "\320\237\320\276\320\264\320\276\320\266\320\264\320\270\321\202\320\265, \320\277\320\276\320\272\320\260 \321\204\320\260\320\271\320\273 \320\261\321\203\320\264\320\265\321\202 \320\267\320\260\320\263\321\200\321\203\320\266\320\265\320\275 \320\262 \320\261\320\260\320\267\321\203 \320\264\320\260\320\275\320\275\321\213\321\205 ...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProgressBar: public Ui_ProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBAR_H
