#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include "calendarview.h"
#include "contactview.h"
#include "eventview.h"
#include "troller.h"
#include "contacthandler.h"
#include "eventhandler.h"
#include "event.h"
#include "contact.h"
#include "eventfeed.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    explicit MainWindow(QWidget *parent = 0);

    void setEventHandler(EventHandler*);
    void setContactHandler(ContactHandler*);

private:

    // Disse gutta kan i grunn opprettes hver gang de trengs..
    //EventView *eventEdit;
    //ContactView *contactEdit;

    CalendarView *calendar;
    EventHandler *eventHandler;
    ContactHandler *contactHandler;

    void createDock();
    void createCalendar();

signals:
    
public slots:
    
};

#endif // MAINWINDOW_H
