#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "extendedqcalendar.h"
#include "eventfeed.h"

class CalendarView : public QWidget
{
    Q_OBJECT
public:
    CalendarView(QWidget *parent = 0);

private:

    QHBoxLayout *mainLayout;
    QVBoxLayout *eventFeed;
    ExtendedQCalendar *calendar;
    //EventFeed *feed;
    QLabel *event;

signals:

public slots:

    void dateClicked(const QDate&) const;

};

#endif // CALENDARVIEW_H
