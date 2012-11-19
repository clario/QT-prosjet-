#include "mainwindow.h"
#include "eventview.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setWindowTitle("TurboCalendar 3000");
    resize(800,600);
    createCalendar();
    setCentralWidget(calendar);

}

void MainWindow::createCalendar() {

    calendar = new ExtendedQCalendar();
    calendar->setCurrentWindow(this);

    connect(calendar, SIGNAL(clicked(QDate)), this, SLOT(dateClicked(QDate)));
}

void MainWindow::setEventHandler(EventHandler *ehandler) {

    eventHandler=ehandler;

}

void MainWindow::setContactHandler(ContactHandler *chandler) {

    contactHandler=chandler;

}

void MainWindow::dateClicked(QDate date) {

    if(eventHandler->eventsExists(date)) {

        QDateTime from(date);
        QDateTime to = from.addDays(1);

        std::vector<Event> events = eventHandler->findEvents(from,to);

        EventView *ev = new EventView;

        ev->setEvent(events.at(0));
        ev->setViewMode();
        ev->show();

    }

}

void MainWindow::dateClicked(QDate date) {
    if(eventHandler->eventsExists(date)) {

        QDateTime from(date);
        QDateTime to = from.addDays(1);

        std::vector<Event> events = eventHandler->findEvents(from,to);
        Event oldEvent = events.at(0);

        EventView *ev = new EventView;

        ev->setEvent(oldEvent);
        ev->setViewMode();
        ev->exec();

        qDebug() << "Endre:" << ev->isChanged();
        if (ev->isChanged()) {
            Event newEvent = ev->getEvent();
            eventHandler->replace(oldEvent, newEvent);

            calendar->update();
        }

    }

}
