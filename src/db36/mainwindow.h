#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <libpq-fe.h>
#include <libpq/libpq-fs.h>
#include "progressbar.h"
#include "blobthread.h"

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
  bool ExecuteSQL(const QString &query);
  void UpdateButtons();

 public slots:
  void Log(QString message, Qt::GlobalColor color = Qt::black);

 private slots:
  void on_action_connect_db_triggered(bool checked);
  void on_action_sql_command_triggered();
  void on_action_upload_blob_to_db_triggered();
  void on_action_download_blob_from_db_triggered();

private:
    Ui::MainWindow *ui;
    QString file_name_;
    Oid     blob_oid_;
    BLOBThread *blob_thread_;
    ProgressBar *progress_bar_;
};

#endif // MAINWINDOW_H
