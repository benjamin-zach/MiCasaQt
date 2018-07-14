#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "xmlparser.h"
#include "shoppinglistgenerator.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWeakPointer<XMLParser> Parser, QWeakPointer<ShoppingListGenerator> Generator, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_addBtn_clicked();

    void on_genBtn_clicked();

private:
    void AddCalendarItem();
    void GenerateShoppingList();

    void GetSelectedRecepies(QStringList& Result);

    Ui::MainWindow *ui;

    QWeakPointer<XMLParser> ParserRef;
    QWeakPointer<ShoppingListGenerator> GeneratorRef;
};

#endif // MAINWINDOW_H
