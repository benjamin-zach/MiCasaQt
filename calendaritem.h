#ifndef CALENDARITEM_H
#define CALENDARITEM_H

#include <QWidget>

namespace Ui {
class CalendarItem;
}

class CalendarItem : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarItem(QWidget *parent = 0);
    ~CalendarItem();

    static QString GetDate(uint DaysFromNow = 0);

private:
    Ui::CalendarItem *ui;

};

#endif // CALENDARITEM_H
