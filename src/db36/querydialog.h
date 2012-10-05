#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include <QDialog>

namespace Ui {
class QueryDialog;
}

class QueryDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit QueryDialog(QWidget *parent = 0);
    ~QueryDialog();
    QString GetQueryText();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::QueryDialog *ui;
    QString query_;
};

#endif // QUERYDIALOG_H
