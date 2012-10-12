#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <libpq-fe.h>
#include <libpq/libpq-fs.h>

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
  void UpdateButtons();

private slots:
    void on_action_connect_db_triggered(bool checked);
    void on_action_sql_command_triggered();
    void on_action_upload_blob_to_db_triggered();
    void on_action_download_blob_from_db_triggered();

private:
    Ui::MainWindow *ui;
    PGconn* db_connection_;
    QString file_name_;
    Oid     blob_oid_;
signals:
    void signalValueChanged(int, int);
};

#endif // MAINWINDOW_H
