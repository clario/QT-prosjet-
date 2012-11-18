#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "extendedqcalendar.h"
#include "troller.h"

class CalendarView : public QWidget
{
    Q_OBJECT
public:
    CalendarView(QWidget *parent = 0);

private:

    QLabel *event;
    QLabel *anotherEvent;
    QHBoxLayout *mainLayout;
    QVBoxLayout *eventFeed;
    ExtendedQCalendar *calendar;
    Troller *troller;

signals:

public slots:

    void dateClicked(const QDate&) const;

};

#endif // CALENDARVIEW_H
