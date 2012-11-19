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

    buttons = new QHBoxLayout();
    deleteEvent = new QPushButton("Slett");
    deleteEvent->setEnabled(false);
    deleteAll = new QPushButton("Slett alle");
    deleteAll->setEnabled(false);

    buttons->addWidget(deleteEvent);
    buttons->addWidget(deleteAll);

    search = new EventSearch();

    wrapper->addWidget(feed);
    wrapper->addLayout(buttons);
    wrapper->addWidget(search);

}

void EventFeed::setCurrentWindow(MainWindow *window) {

    currentWindow=window;

    buildConnections();

}

void EventFeed::loadEvents(const std::vector<Event> &events) {

    QStringList eventList;

    for(int eventAmnt=0 ; eventAmnt < (unsigned)events.size() ; eventAmnt++){

        eventList << events.at(eventAmnt).getTitle();

    }

    feed->clear();
    feed->addItems(eventList);

}

void EventFeed::buildConnections() {

    connect(feed, SIGNAL(clicked(QModelIndex)), this, SLOT(toggleButtons()));
    connect(feed, SIGNAL(doubleClicked(QModelIndex)), currentWindow, SLOT(rowDoubleClicked(QModelIndex)));
    connect(search, SIGNAL(queryArgs(const EventHandler::QueryArgs&)), currentWindow, SLOT(searchEvent(const EventHandler::QueryArgs&)));
    connect(deleteEvent, SIGNAL(clicked()), currentWindow, SLOT(deleteEvent()));
    connect(deleteAll, SIGNAL(clicked()), currentWindow, SLOT(deleteAllEventsToday()));

}

void EventFeed::toggleButtons() {

    deleteEvent->setEnabled(true);
    deleteAll->setEnabled(true);

}

// Røverløsning..

void EventFeed::deactivate() {

    deleteEvent->setEnabled(false);
    deleteAll->setEnabled(false);

}

void EventFeed::clearEventFeed() {

    feed->clear();

}

int EventFeed::getActiveEvent() {

    return feed->currentRow();

}
