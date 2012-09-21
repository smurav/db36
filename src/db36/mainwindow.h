#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    
private slots:
    void on_action_connect_db_triggered(bool checked);

 private:
  bool ConnectToDB();
  void DisconnectFromDB();

private:
    Ui::MainWindow *ui;
    PGconn* db_connection_;
};

#endif // MAINWINDOW_H
