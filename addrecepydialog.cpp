#include "addrecepydialog.h"
#include "ui_addrecepydialog.h"

AddRecepyDialog::AddRecepyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecepyDialog)
{
    ui->setupUi(this);
}

AddRecepyDialog::~AddRecepyDialog()
{
    delete ui;
}
