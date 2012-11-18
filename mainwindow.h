#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "contactview.h"
#include "eventview.h"
#include "contacthandler.h"
#include "eventhandler.h"
#include "extendedqcalendar.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

    void setEventHandler(EventHandler*);
    void setContactHandler(ContactHandler*);

private:


    ExtendedQCalendar *calendar;
    //EventView *eventEdit;
    //ContactView *contactEdit;
    //Troller *troller;
    ContactHandler *contactHandler;
    EventHandler *eventHandler;

    //QDockWidget *dock;

    void createCalendar();

signals:
    
public slots:
    
};

#endif // MAINWINDOW_H
