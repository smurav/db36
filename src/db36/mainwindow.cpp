#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "querydialog.h"
//#include "/usr/include/pgsql//server/catalog/pg_type.h"

#define BUF_SIZE 1024

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
  ui->setupUi(this);
  db_connection_ = 0;
  blob_oid_ = 0;
  blob_thread_ = 0;
  progress_bar_ = 0;
  UpdateButtons();
}

MainWindow::~MainWindow() {
  DisconnectFromDB();
  if (ui) {
    delete ui;
    ui = 0;
  }
}

void MainWindow::on_action_connect_db_triggered(bool checked) {
    if (checked) {
        ConnectToDB();
    } else {
        DisconnectFromDB();
    }
}

bool MainWindow::ConnectToDB() {
  DisconnectFromDB();
  QString connection_string = "dbname=mephi user=postgres password=123456";
  db_connection_ = PQconnectdb(connection_string.toAscii().data());
  qDebug() << PQsetClientEncoding(db_connection_,"UNICODE");
  if (PQstatus(db_connection_) == CONNECTION_BAD) {
    QMessageBox::critical(0,
                          tr("Ошибка"),
                          PQerrorMessage(db_connection_),
                          QMessageBox::Ok);
    PQfinish(db_connection_);
    db_connection_ = 0;
    return false;
  }
  UpdateButtons();
  Log(tr("Соединение с БД установлено\n"), Qt::darkGreen);
  return true;
}

void MainWindow::DisconnectFromDB() {
  if (db_connection_) {
    PQfinish(db_connection_);
    db_connection_ = 0;
    Log(tr("Соединение с БД разорвано\n"), Qt::darkRed);
  }
  UpdateButtons();
}

void MainWindow::Log(QString message, Qt::GlobalColor color) {
  QTextCharFormat text_format;
  text_format.setForeground(QBrush(color));
  QTextCursor cursor(ui->log->textCursor());
  cursor.insertText(message, text_format);
}

bool MainWindow::ExecuteSQL(const QString &query) {
  Log(tr("SQL >> %1\n").arg(query), Qt::darkBlue);
  PGresult *result = PQexecParams(db_connection_, query.toLocal8Bit(), 0, 0, 0, 0, 0, 1);
  ExecStatusType status = PQresultStatus(result);
  if(PGRES_COMMAND_OK == status) {
    /* first, print out the attribute names */
    int fields_count = PQnfields(result);
    for (int i = 0; i < fields_count; i++)
      Log(tr("%1 (%2) | ").arg(QString::fromLocal8Bit(PQfname(result, i)),10).
                           arg(PQftype(result, i)));
    Log("\n");
    /* next, print out the rows */
    for (int i = 0; i < PQntuples(result); i++) {
      for (int j = 0; j < fields_count; j++) {
        Log(tr("%1 | ").arg(QString::fromLocal8Bit(PQgetvalue(result, i, j)),10));
      }
      Log("\n");
    }
  } else {
    Log(QString::fromLocal8Bit(PQerrorMessage(db_connection_)), Qt::darkRed);
  }
  if (result) {
    PQclear(result);
    result = 0;
  }
  return true;
}

void MainWindow::on_action_sql_command_triggered() {
  QueryDialog dialog(this);
  if (QDialog::Accepted == dialog.exec()) {
    ExecuteSQL(dialog.GetQueryText());
  }
}

void MainWindow::UpdateButtons() {
  bool connected = CONNECTION_OK == PQstatus(db_connection_);
  if (ui) {
    ui->action_connect_db->setChecked(connected);
    ui->action_sql_command->setEnabled(connected);
    ui->action_upload_blob_to_db->setEnabled(connected && (0 == blob_thread_));
    ui->action_download_blob_from_db->setEnabled(connected && blob_oid_ && (0 == blob_thread_));
  }
}

void MainWindow::on_action_upload_blob_to_db_triggered() {
  if (blob_thread_ || progress_bar_)
    return;

  file_name_ = QFileDialog::getOpenFileName(this,
                                                  tr("Выберите файл для загрузки в БД"),
                                                  file_name_);
  if (0 == file_name_.length())
    return;

  PGresult *result = PQexec(db_connection_, "begin");
  PQclear(result);
  blob_oid_ = lo_create(db_connection_, 0);
  result = PQexec(db_connection_, "end");
  PQclear(result);

  blob_thread_ = new BLOBThread(this, db_connection_, file_name_, blob_oid_);
  if (0 == blob_thread_)
    return;
  connect(blob_thread_,
          SIGNAL(Log(QString, Qt::GlobalColor)),
          this,
          SLOT(Log(QString, Qt::GlobalColor)));
  connect(blob_thread_,
          SIGNAL(SignalProgressChanged(int)),
          progress_bar_,
          SLOT(slotSetValueOnProgressBar(int)));

  QFile file(file_name_);
  progress_bar_ = new ProgressBar(this);
  if (0 == progress_bar_) {
    delete blob_thread_;
    blob_thread_ = 0;
  }
  progress_bar_->SetMaximum(file.size());
  progress_bar_->show();

  blob_thread_->start();

  UpdateButtons();
}

void MainWindow::on_action_download_blob_from_db_triggered() {
  if (0 == blob_oid_)
    return;

  file_name_ = QFileDialog::getSaveFileName(this, tr("Сохранить как"), file_name_);
  if (0 == file_name_.length())
    return;

  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));

  QFile file(file_name_);
  if (file.open(QIODevice::Truncate | QIODevice::WriteOnly)) {
    PGresult *result = PQexec(db_connection_, "begin");
    PQclear(result);
    int blob_fd = lo_open(db_connection_, blob_oid_, INV_READ);
    if (blob_fd < 0) {
        Log(QString::fromLocal8Bit(PQerrorMessage(db_connection_)), Qt::darkRed);
        Log(tr("Ошибка открытия BLOBа\n"), Qt::darkRed);
    } else {
      int nbytes = 0;
      char buf[BUF_SIZE];
      while ((nbytes = lo_read(db_connection_, blob_fd, buf, BUF_SIZE)) > 0) {
        if (file.write(buf, nbytes) < nbytes) {
          Log(QString::fromLocal8Bit(PQerrorMessage(db_connection_)), Qt::darkRed);
          break;
        }
      }
      lo_close(db_connection_, blob_fd);
      Log(tr("Файл %1 записан\n").arg(file_name_), Qt::darkGreen);
    }

    result = PQexec(db_connection_, "end");
    PQclear(result);
  }

  QApplication::restoreOverrideCursor();
}
