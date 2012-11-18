#ifndef EVENTFEED_H
#define EVENTFEED_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include "eventwidget.h"

class EventFeed : public QWidget
{

    Q_OBJECT

public:
    explicit EventFeed(QWidget *parent = 0);

private:

    // Å heii
    QVBoxLayout *feed;
    EventWidget *demo;


};

#endif // EVENTFEED_H