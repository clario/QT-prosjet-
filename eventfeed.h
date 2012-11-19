#ifndef EVENTFEED_H
#define EVENTFEED_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "eventwidget.h"
#include "eventsearch.h"
#include <QPushButton>
#include <QListWidget>
#include "mainwindow.h"
#include <vector>

class MainWindow;

class EventFeed : public QWidget
{

    Q_OBJECT

public:
    explicit EventFeed(QWidget *parent = 0);

    void setCurrentWindow(MainWindow*);
    void loadEvents(const std::vector<Event>&);
    void deactivate();
    void clearEventFeed();
    int getActiveEvent();

private:

    // Å heii
    QPushButton *deleteEvent;
    QPushButton *deleteAll;
    QHBoxLayout *buttons;
    QVBoxLayout *wrapper;
    QListWidget *feed;
    EventSearch *search;
    MainWindow *currentWindow;

    void buildConnections();

private slots:

    void toggleButtons();
    //void rowClicked();

};

#endif // EVENTFEED_H
