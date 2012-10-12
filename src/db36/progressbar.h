#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <QDialog>

namespace Ui {
class ProgressBar;
}

class ProgressBar : public QDialog
{
    Q_OBJECT
    
public:
    explicit ProgressBar(QWidget *parent = 0);
    ~ProgressBar();
 public:
  void SetMaximum(int maximum_value = 100);

private:
    Ui::ProgressBar *ui;
    int progress_;
public slots:
    void slotSetValueOnProgressBar(int progress);
private slots:
    void on_ProgressBar_rejected();
};

#endif // PROGRESSBAR_H
