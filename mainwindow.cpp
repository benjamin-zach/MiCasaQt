#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statics.h"
#include "calendaritem.h"
#include "logger.h"

#include <QLabel>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    AddCalendarItem();
}

void MainWindow::on_addBtn_clicked()
{
    AddCalendarItem();
}

void MainWindow::AddCalendarItem()
{
    //Creating a new list widget item whose parent is the listwidget itself
    QListWidgetItem *listWidgetItem = new QListWidgetItem(ui->listWidget);

    //Adding the item to the listwidget
    ui->listWidget->addItem (listWidgetItem);

    //Creating an object of the designed widget which is to be added to the listwidget
    CalendarItem* Item = new CalendarItem();
    QLabel* Label = Item->findChild<QLabel*>("label");
    uint ElementNumber = ui->listWidget->count();
    QString DateText = CalendarItem::GetDate(ElementNumber);
    Label->setText(DateText);

    //Making sure that the listWidgetItem has the same size as the Item
    listWidgetItem->setSizeHint (Item->sizeHint ());

    //Finally adding the itemWidget to the list
    ui->listWidget->setItemWidget (listWidgetItem, Item);

}

void MainWindow::GenerateShoppingList()
{
    QStringList Recepies;
    GetSelectedRecepies(Recepies);
    ShoppingList sl = Statics::Instance().generator()->GetShoppingList(Recepies);
    MiCasaLogger::toString(sl);
}

void MainWindow::GetSelectedRecepies(QStringList& Result)
{
    for(int i = 0; i < ui->listWidget->count(); ++i)
    {
        for(QComboBox* ComboBox : ui->listWidget->findChildren<QComboBox*>())
        {
            Result.append(ComboBox->currentText());
        }
    }
}

void MainWindow::on_genBtn_clicked()
{
    GenerateShoppingList();
}
