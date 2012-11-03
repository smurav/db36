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
    void setMaximum(int maximum_value);
    
private:
    Ui::ProgressBar *ui;
    int loaded_bytes_;
public slots:
    void slotSetValueOnProgressBar(int written_bytes);
private slots:
    void on_cancel_button__clicked();
};

#endif // PROGRESSBAR_H
