#include "filechooser.h"
#include "ui_filechooser.h"

FileChooser::FileChooser(std::function<void(const QString&)> InSetterFct, QWidget *parent) :
    QDialog(parent),
    SetterFct(InSetterFct),
    ui(new Ui::FileChooser)
{
    ui->setupUi(this);
}

FileChooser::~FileChooser()
{
    delete ui;
}

void FileChooser::on_buttonBox_accepted()
{
    QString FilePath;
    if(GetChoosenFilePath(FilePath))
    {
        SetterFct(FilePath);
    }
    else
    {
        //TODO: log #zach
    }

}

void FileChooser::on_buttonBox_rejected()
{

}

bool FileChooser::GetChoosenFilePath(QString &OutFilePath)
{
    OutFilePath = ""; //  TODO: #zach
    return false;
}
