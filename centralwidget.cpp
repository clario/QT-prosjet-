#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent) :
    QWidget(parent)
{

    setWindowTitle("CentralWidget");
    resize(600,400);
    mainLayout = new QHBoxLayout(this);
    calendar = new ExtendedQCalendar();
    calendar->setGridVisible(true);
    mainLayout->addWidget(calendar);

    eventFeed = new QVBoxLayout();
    eventFeed->setAlignment(Qt::AlignTop);

    mainLayout->addLayout(eventFeed);

    event = new QLabel("Hallaien");
    anotherEvent = new QLabel("Nei Heisann");

    eventFeed->addWidget(event);
    eventFeed->addWidget(anotherEvent);


}
