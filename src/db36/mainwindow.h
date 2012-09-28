#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <libpq-fe.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
  bool ConnectToDB();
  void DisconnectFromDB();
  void Log(const QString &message, Qt::GlobalColor color = Qt::black);
  bool ExecuteSQL(const QString &query);

private slots:
    void on_action_connect_db_triggered(bool checked);
    void on_action_sql_command_triggered();

private:
    Ui::MainWindow *ui;
    PGconn* db_connection_;
};

#endif // MAINWINDOW_H
