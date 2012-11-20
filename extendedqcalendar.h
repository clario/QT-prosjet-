#ifndef EXTENDEDQCALENDAR_H
#define EXTENDEDQCALENDAR_H

#include <QCalendarWidget>
#include <QColor>
#include <QDate>
#include <QPen>
#include <QBrush>
#include "mainwindow.h"

class MainWindow;

class ExtendedQCalendar : public QCalendarWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ getColor WRITE setColor)

public:
    ExtendedQCalendar(QWidget *parent = 0);

    QColor getColor();
    void setColor(QColor &color);
    void setCurrentWindow(MainWindow*);

protected:

   virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:

   QPen m_outlinePen;
   QBrush m_transparentBrush;

   MainWindow *currentWindow;

signals:

public slots:

};

#endif // EXTENDEDQCALENDAR_H
