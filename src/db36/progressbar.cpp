#include "progressbar.h"
#include "ui_progressbar.h"
#include <QDebug>

ProgressBar::ProgressBar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressBar) {
    ui->setupUi(this);
    progress_ = 0;
}

ProgressBar::~ProgressBar() {
    delete ui;
}

void ProgressBar::SetMaximum(int maximum_value) {
  ui->progress_bar_->setMaximum(maximum_value);
}

void ProgressBar::slotSetValueOnProgressBar(int progress) {
    progress_ += progress;
    ui ->progress_bar_->setValue(progress_);
}

void ProgressBar::on_ProgressBar_rejected() {
  ui ->progress_bar_->setValue(0);
}


