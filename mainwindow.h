#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calendarview.h"
#include "contactview.h"
#include "eventview.h"
#include "troller.h"
#include "contacthandler.h"
#include "eventhandler.h"
#include "event.h"
#include "contact.h"



class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    MainWindow(Troller *troll, ContactHandler *chandler, EventHandler *ehandler);

private:

    CalendarView *calendar;
    EventView *eventEdit;
    ContactView *contactEdit;
    Troller *troller;
    ContactHandler *contactHandler;
    EventHandler *eventHandler;

    QDockWidget *dock;

    void createDock();
    void createCalendar();


signals:
    
public slots:
    
};

#endif // MAINWINDOW_H
