#include "extendedqcalendar.h"
#include <QPainter>
#include <QDebug>
#include <QDateTime>

ExtendedQCalendar::ExtendedQCalendar(QWidget *parent) :
    QCalendarWidget(parent)
{

    m_currentDate = QDate(2012,11,21);
    anotherDate = QDate(2012,11,10);
    m_outlinePen.setColor(Qt::red);
    m_transparentBrush.setColor(Qt::black);

}


void ExtendedQCalendar::setColor(QColor &color) {

    m_outlinePen.setColor(color);

}

QColor ExtendedQCalendar::getColor() {

    return (m_outlinePen.color());

}

void ExtendedQCalendar::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
     QCalendarWidget::paintCell(painter, rect, date);

     if(currentWindow->eventHandler->eventsExists(date)) {

         painter->setPen(m_outlinePen);
         painter->setBrush(m_transparentBrush);
         painter->drawRect(rect.adjusted(0, 0, -1, -1));

     }

}

void ExtendedQCalendar::setCurrentWindow(MainWindow *window) {

    currentWindow=window;

}
