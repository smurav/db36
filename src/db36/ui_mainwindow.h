/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Oct 12 10:10:50 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_connect_db;
    QAction *action_sql_command;
    QAction *action_upload_blob_to_db;
    QAction *action_download_blob_from_db;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *log;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(569, 418);
        action_connect_db = new QAction(MainWindow);
        action_connect_db->setObjectName(QString::fromUtf8("action_connect_db"));
        action_connect_db->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/db_connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_connect_db->setIcon(icon);
        action_sql_command = new QAction(MainWindow);
        action_sql_command->setObjectName(QString::fromUtf8("action_sql_command"));
        action_sql_command->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/command.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_sql_command->setIcon(icon1);
        action_upload_blob_to_db = new QAction(MainWindow);
        action_upload_blob_to_db->setObjectName(QString::fromUtf8("action_upload_blob_to_db"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_upload_blob_to_db->setIcon(icon2);
        action_download_blob_from_db = new QAction(MainWindow);
        action_download_blob_from_db->setObjectName(QString::fromUtf8("action_download_blob_from_db"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_download_blob_from_db->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(3);
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        log = new QTextEdit(centralWidget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setReadOnly(true);

        gridLayout->addWidget(log, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 569, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setIconSize(QSize(16, 16));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(action_connect_db);
        mainToolBar->addAction(action_sql_command);
        mainToolBar->addAction(action_upload_blob_to_db);
        mainToolBar->addAction(action_download_blob_from_db);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "db36", 0, QApplication::UnicodeUTF8));
        action_connect_db->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\214\321\201\321\217 \321\201 \320\221\320\224", 0, QApplication::UnicodeUTF8));
        action_sql_command->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\274\320\260\320\275\320\264\320\260 SQL", 0, QApplication::UnicodeUTF8));
        action_upload_blob_to_db->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\265\321\201\321\202\320\270\321\202\321\214 \321\204\320\260\320\271\320\273 \320\262 \320\221\320\224", 0, QApplication::UnicodeUTF8));
        action_download_blob_from_db->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273 \320\270\320\267 \320\221\320\224", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
