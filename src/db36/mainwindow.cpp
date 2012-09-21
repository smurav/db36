#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db_connection_ = 0;
}

MainWindow::~MainWindow() {
  if (ui) {
    delete ui;
    ui = 0;
  }
  DisconnectFromDB();
}

void MainWindow::on_action_connect_db_triggered(bool checked) {
    if (checked) {
        ConnectToDB();
    } else {
        DisconnectFromDB();
    }
}

bool MainWindow::ConnectToDB() {
  return true;
}

void MainWindow::DisconnectFromDB() {
  if (db_connection_) {
    PQfinish(db_connection_);
    db_connection_ = 0;
  }
}

