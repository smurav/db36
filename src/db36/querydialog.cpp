#include "querydialog.h"
#include "ui_querydialog.h"

QueryDialog::QueryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryDialog)
{
    ui->setupUi(this);
}

QueryDialog::~QueryDialog()
{
    delete ui;
}

QString QueryDialog::GetQueryText() {
  return query_;
 }

void QueryDialog::on_buttonBox_accepted() {
  query_ = ui->sql_query->text();
}
