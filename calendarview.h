#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "extendedqcalendar.h"

class CalendarView : public QWidget
{
    Q_OBJECT
public:
    explicit CalendarView(QWidget *parent = 0);

private:

    QLabel *event;
    QLabel *anotherEvent;
    QHBoxLayout *mainLayout;
    QVBoxLayout *eventFeed;
    ExtendedQCalendar *calendar;

signals:

public slots:

};

#endif // CALENDARVIEW_H
