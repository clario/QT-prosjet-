#include "eventfeed.h"
#include <QLabel>

EventFeed::EventFeed(QWidget *parent) :
    QWidget(parent)
{

    //wrapper = new QVBoxLayout();
    demo = new EventWidget();
    eventArea = new QScrollArea(this);
    eventArea->setWidget(new QLabel("HFUEIWH"));
    //wrapper->addWidget(demo);
    //wrapper->addWidget(new QLabel("BAAASJ!!"));

}
