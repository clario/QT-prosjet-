// VOID!!

#ifndef EVENTFEED_H
#define EVENTFEED_H

#include <QWidget>
#include <QVBoxLayout>
#include "eventwidget.h"
#include <QPushButton>
//#include <QStringList>
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
    void loadEvents(std::vector<Event> events);

private:

    // Å heii
    QVBoxLayout *wrapper;
    QListWidget *feed;
    //QStringList *eventList;
    QPushButton *search;
    MainWindow *currentWindow;

private slots:

    //void rowClicked();

};

#endif // EVENTFEED_H
