#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMainWindow>
#include <QDockWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <vector>
#include "contactview.h"
#include "eventview.h"
#include "contacthandler.h"
#include "eventhandler.h"
//#include "extendedqcalendar.h"
//#include "eventfeed.h"

class ExtendedQCalendar;
class EventFeed;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

    ContactHandler *contactHandler;
    EventHandler *eventHandler;

    void setEventHandler(EventHandler*);
    void setContactHandler(ContactHandler*);

private:

    ExtendedQCalendar *calendar;
    //EventView *eventEdit;
    //ContactView *contactEdit;
    //Troller *troller;


    QDockWidget *dock;
    EventFeed *feed;

    QMenuBar *menu;
    QMenu *fileMenu;
    QMenu *contactsMenu;

    QAction *aboutAct;
    QAction *saveAct;
    QAction *quitAct;
    QAction *viewContacts;
    QAction *addContact;

    std::vector<Event> events;

    void createCalendar();
    void createDock();
    void createActions();
    void createMenus();
    void createConnections();


signals:
    
public slots:
    
    void dateClicked(QDate);
    void rowDoubleClicked(const QModelIndex&);
    void about();
    void searchEvent(const EventHandler::QueryArgs&);
    void deleteEvent();
    void deleteAllEventsToday();

};

#endif // MAINWINDOW_H
