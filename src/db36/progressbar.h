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
    
private:
    Ui::ProgressBar *ui;
    int loaded_bytes_;
public slots:
    void slotSetValueOnProgressBar(int written_bytes, int file_size);
};

#endif // PROGRESSBAR_H
