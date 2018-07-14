#ifndef CALENDARITEM_H
#define CALENDARITEM_H

#include "xmlparser.h"
#include <QWidget>

namespace Ui {
class CalendarItem;
}

class CalendarItem : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarItem(QWeakPointer<XMLParser> Parser, QWidget *parent = 0);
    ~CalendarItem();

    static QString GetDate(uint DaysFromNow = 0);

private:
    Ui::CalendarItem *ui;

    QWeakPointer<XMLParser> ParserRef;

};

#endif // CALENDARITEM_H
