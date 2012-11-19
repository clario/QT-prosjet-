// VOID!!

#include "eventfeed.h"
#include "event.h"
#include <iostream>
#include <QDebug>

EventFeed::EventFeed(QWidget *parent) :
    QWidget(parent)
{

    // Heisann
    wrapper = new QVBoxLayout(this);
    feed = new QListWidget();
    //QStringList eventList;

    //eventList << "Placeholder" << "Placeholder 2";

    //feed->addItems(eventList);

    wrapper->addWidget(feed);

    search = new QPushButton("Search and shit");

    wrapper->addWidget(search);

}

void EventFeed::setCurrentWindow(MainWindow *window) {

    currentWindow=window;
    connect(feed, SIGNAL(clicked(QModelIndex)), currentWindow, SLOT(rowClicked(QModelIndex)));

}

/*

void EventFeed::rowClicked() {

    std::cout << feed->currentRow() << std::endl;

}

*/

void EventFeed::loadEvents(std::vector<Event> events) {

    QStringList eventList;

    qDebug("Ugh");

    for(int eventAmnt=0 ; eventAmnt < events.size() ; eventAmnt++){

        eventList << events.at(eventAmnt).getTitle();

    }

    feed->clear();
    feed->addItems(eventList);

}
