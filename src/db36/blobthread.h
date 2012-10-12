#ifndef BLOBTHREAD_H
#define BLOBTHREAD_H

#include <QThread>
#include <libpq-fe.h>
#include <libpq/libpq-fs.h>

class BLOBThread : public QThread
{
    Q_OBJECT
public:
    explicit BLOBThread(QObject *parent,
                        PGconn *db_connection,
                        const QString &file_name,
                        Oid blob_oid,
                        bool write = true);

public:
  void run();

signals:
  void Log(QString message, Qt::GlobalColor color);
  void SignalProgressChanged(int progress);

public slots:

private:
  PGconn  *db_connection_;
  QString file_name_;
  Oid     blob_oid_;
  bool    write_;
};

#endif // BLOBTHREAD_H
