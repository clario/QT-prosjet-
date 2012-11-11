#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "extendedqcalendar.h"

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = 0);

private:

    QLabel *event;
    QLabel *anotherEvent;
    QHBoxLayout *mainLayout;
    QVBoxLayout *eventFeed;
    ExtendedQCalendar *calendar;

signals:

public slots:

};

#endif // CENTRALWIDGET_H
