#include "calendarview.h"
#include <QDebug>

CalendarView::CalendarView(QWidget *parent) :
    QWidget(parent)
{

    calendar = new ExtendedQCalendar();
    calendar->setGridVisible(true);

    connect(calendar, SIGNAL(clicked(QDate)), this, SLOT(dateClicked(QDate)));


}

void CalendarView::dateClicked(const QDate &date) const {

    qDebug() << date;

}
