#ifndef EXTENDEDQCALENDAR_H
#define EXTENDEDQCALENDAR_H

#include <QCalendarWidget>
#include <QColor>
#include <QDate>
#include <QPen>
#include <QBrush>

class ExtendedQCalendar : public QCalendarWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ getColor WRITE setColor)

public:
    ExtendedQCalendar(QWidget *parent = 0);

    void setColor(QColor &color);
    QColor getColor();

protected:

   virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:
   QDate m_currentDate;
   QPen m_outlinePen;
   QBrush m_transparentBrush;

signals:

public slots:

};

#endif // EXTENDEDQCALENDAR_H
