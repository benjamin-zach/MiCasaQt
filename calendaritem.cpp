#include "calendaritem.h"
#include "ui_calendaritem.h"

CalendarItem::CalendarItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarItem)
{
    ui->setupUi(this);
}

CalendarItem::~CalendarItem()
{
    delete ui;
}
