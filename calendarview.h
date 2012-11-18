#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QWidget>
#include "extendedqcalendar.h"

class CalendarView : public QWidget
{
    Q_OBJECT
public:
    CalendarView(QWidget *parent = 0);

private:

    ExtendedQCalendar *calendar;

signals:

public slots:

    void dateClicked(const QDate&) const;

};

#endif // CALENDARVIEW_H
