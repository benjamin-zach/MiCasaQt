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

private:
    Ui::CalendarItem *ui;
};

#endif // CALENDARITEM_H
