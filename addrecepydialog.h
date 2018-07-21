#ifndef ADDRECEPYDIALOG_H
#define ADDRECEPYDIALOG_H

#include <QDialog>

namespace Ui {
class AddRecepyDialog;
}

class AddRecepyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecepyDialog(QWidget *parent = 0);
    ~AddRecepyDialog();

private:
    Ui::AddRecepyDialog *ui;
};

#endif // ADDRECEPYDIALOG_H
