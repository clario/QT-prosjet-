#include "eventfeed.h"
#include <QLabel>

EventFeed::EventFeed(QWidget *parent) :
    QWidget(parent)
{

    // Heisann
    feed = new QVBoxLayout();
    demo = new EventWidget();
    feed->addWidget(demo);

}
