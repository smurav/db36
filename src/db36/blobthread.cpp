#include "blobthread.h"

BLOBThread::BLOBThread(QObject *parent) :
    QThread(QObject *parent,
            PGconn *db_connection,
            const QString &file_name,
            Oid blob_oid_,
            bool write ) : {
}

void BLOBThread::run() {

}
