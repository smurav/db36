#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "querydialog.h"
//#include "/usr/include/pgsql//server/catalog/pg_type.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db_connection_ = 0;
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
  QString connection_string = "dbname=test user=postgres password=123456";
  db_connection_ = PQconnectdb(connection_string.toAscii().data());
  if (PQstatus(db_connection_) == CONNECTION_BAD) {
    QMessageBox::critical(0,
                          tr("Ошибка"),
                          tr(PQerrorMessage(db_connection_)),
                          QMessageBox::Ok);
    return false;
  }
  ui->action_connect_db->setChecked(true);
  ui->action_sql_command->setEnabled(true);
  Log(tr("Соединение с БД установлено\n"), Qt::darkGreen);
  return true;
}

void MainWindow::DisconnectFromDB() {
  if (db_connection_) {
    PQfinish(db_connection_);
    db_connection_ = 0;
    Log(tr("Соединение с БД разорвано\n"), Qt::darkRed);
  }
  ui->action_connect_db->setChecked(false);
  ui->action_sql_command->setEnabled(false);
}

void MainWindow::Log(const QString &message, Qt::GlobalColor color) {
  QTextCharFormat text_format;
  text_format.setForeground(QBrush(color));
  QTextCursor cursor(ui->log->textCursor());
  cursor.insertText(message, text_format);
}

bool MainWindow::ExecuteSQL(const QString &query) {
  Log(tr("SQL >> %1\n").arg(query), Qt::darkBlue);
  PGresult *result = PQexecParams(db_connection_, query.toLocal8Bit(), 0, 0, 0, 0, 0, 1);
  ExecStatusType status = PQresultStatus(result);
  if((PGRES_COMMAND_OK == status) || (PGRES_TUPLES_OK == status)) {
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
  static QueryDialog dialog;
  if (QDialog::Accepted == dialog.exec()) {
    ExecuteSQL(dialog.GetQueryText());
  }
}
