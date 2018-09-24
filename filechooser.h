#ifndef FILECHOOSER_H
#define FILECHOOSER_H

#include <QDialog>
#include <functional>

namespace Ui {
class FileChooser;
}

class FileChooser : public QDialog
{
    Q_OBJECT

public:
    explicit FileChooser(std::function<void(const QString&)> InSetterFct, QWidget *parent = 0);
    ~FileChooser();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:

    bool GetChoosenFilePath(QString& OutFilePath);

    std::function<void(const QString&)> SetterFct;
    Ui::FileChooser *ui;
};

#endif // FILECHOOSER_H
