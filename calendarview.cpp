#include "calendarview.h"
#include <QDebug>
#include "eventwidget.h"

CalendarView::CalendarView(QWidget *parent) :
    QWidget(parent)
{

    mainLayout = new QHBoxLayout(this);

    calendar = new ExtendedQCalendar();
    calendar->setGridVisible(true);
    mainLayout->addWidget(calendar);

    eventFeed = new QVBoxLayout();
    eventFeed->setAlignment(Qt::AlignTop);

    //feed = new EventFeed();

    mainLayout->addLayout(eventFeed);

    mainLayout->addLayout(eventFeed);

    event = new QLabel("Hallaien");

    //anotherEvent = new QLabel("Nei Heisann");

    eventFeed->addWidget(event);
    eventFeed->addWidget(new EventWidget());

    //eventFeed->addWidget(anotherEvent);


    connect(calendar, SIGNAL(clicked(QDate)), this, SLOT(dateClicked(QDate)));


}

void CalendarView::dateClicked(const QDate &date) const {

    qDebug() << date;

}
