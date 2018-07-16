#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addBtn_clicked();

    void on_genBtn_clicked();

private:
    void AddCalendarItem();
    void GenerateShoppingList();

    void GetSelectedRecepies(QStringList& Result);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
