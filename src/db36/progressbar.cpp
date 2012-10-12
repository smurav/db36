#include "progressbar.h"
#include "ui_progressbar.h"
#include <QDebug>

ProgressBar::ProgressBar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProgressBar) {
    ui->setupUi(this);
    loaded_bytes_ = 0;
}

ProgressBar::~ProgressBar() {
    delete ui;
}


void ProgressBar::slotSetValueOnProgressBar(int written_bytes, int file_size) {
    loaded_bytes_ += written_bytes;
    ui -> progress_bar_ -> setValue(loaded_bytes_ / file_size);
}
