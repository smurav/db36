#include "blobthread.h"
#include <QtGui>

BLOBThread::BLOBThread(QObject *parent,
                       PGconn *db_connection,
                       const QString &file_name,
                       Oid blob_oid,
                       bool write) :
    QThread(parent),
    db_connection_(db_connection),
    file_name_(file_name),
    blob_oid_(blob_oid),
    write_(write){
}

void BLOBThread::run() {
  QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
  if (write_) {
      emit Log(tr("Начало записи файла %1 в блоб").arg(file_name_), Qt::darkGreen);
      for (int i = 0; i < 1000000; i++)
          for (int j = 0; j < 100000000; j++)
              int k = i+j;
/*      if (file.open(QIODevice::ReadOnly)) {
        ProgressBar *progress_bar = new ProgressBar(this);
        progress_bar->SetMaximum(file.size());
        connect(this, SIGNAL(signalValueChanged(int)), progress_bar, SLOT(slotSetValueOnProgressBar(int)));
        progress_bar -> show();
        PGresult *result = PQexec(db_connection_, "begin");
        PQclear(result);
        blob_oid_ = lo_create(db_connection_, 0);
        if (blob_oid_) {
          int blob_fd = lo_open(db_connection_, blob_oid_, INV_WRITE);
          if (-1 == blob_fd) {
            Log(QString::fromLocal8Bit(PQerrorMessage(db_connection_)), Qt::darkRed);
            Log(tr("Ошибка открытия BLOBа\n"), Qt::darkRed);
          } else {
            while (!file.atEnd()) {
              QByteArray buffer = file.read(BUF_SIZE);
              if (buffer.size()) {
                int bytes_written = lo_write(db_connection_, blob_fd, buffer.data(), buffer.size());
                if (bytes_written < buffer.size()) {
                  Log(QString::fromLocal8Bit(PQerrorMessage(db_connection_)), Qt::darkRed);
                  break;
                }
                emit signalValueChanged(bytes_written);
              }
            }
            Log(tr("BLOB записан\n"), Qt::darkGreen);
            lo_close(db_connection_, blob_fd);
          }
        } else {
          Log(QString::fromLocal8Bit(PQerrorMessage(db_connection_)), Qt::darkRed);
        }
        file.close();
        result = PQexec(db_connection_, "end");
        PQclear(result);
      }*/
      emit Log(tr("Файл %1 записан в блоб").arg(file_name_), Qt::darkGreen);
  } else {

  }
  QApplication::restoreOverrideCursor();
}
