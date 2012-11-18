#include "eventfeed.h"

EventFeed::EventFeed(QWidget *parent) :
    QWidget(parent)
{

    // Heisann
    feed = new QVBoxLayout();
    knapp = new QPushButton("BLUARG!");
    //demo = new EventWidget();
    feed->addWidget(knapp);

}
