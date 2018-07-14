#include "calendaritem.h"
#include "ui_calendaritem.h"
#include <QComboBox>
#include <chrono>
#include <ctime>

CalendarItem::CalendarItem(QWeakPointer<XMLParser> Parser, QWidget *parent) :
    ParserRef(Parser),
    QWidget(parent),
    ui(new Ui::CalendarItem)
{
    ui->setupUi(this);
    QStringList RecepiesNames;
    ParserRef.data()->GetRecepiesNames(RecepiesNames);
    for(auto DropDown : this->findChildren<QComboBox*>())
    {
        DropDown->addItems(RecepiesNames);
    }
}

CalendarItem::~CalendarItem()
{
    delete ui;
}

QString CalendarItem::GetDate(uint DaysFromNow)
{
    std::chrono::time_point<std::chrono::system_clock> Now = std::chrono::system_clock::now();
    std::time_t Time = std::chrono::system_clock::to_time_t(Now + std::chrono::hours(24 * DaysFromNow));
    QString TimeString (std::ctime(&Time));
    return TimeString.left(10);
}
