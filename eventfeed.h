// VOID!!

#ifndef EVENTFEED_H
#define EVENTFEED_H

#include <QWidget>
#include <QVBoxLayout>
#include "eventwidget.h"
#include <QPushButton>

class EventFeed : public QWidget
{

    Q_OBJECT

public:
    explicit EventFeed(QWidget *parent = 0);

private:

    // Å heii
    QVBoxLayout *feed;
    //EventWidget *demo;
    QPushButton *knapp;

};

#endif // EVENTFEED_H
