#include <QMessageBox>
#include "mainwindow.h"
#include "extendedqcalendar.h"
#include "eventfeed.h"
#include "eventview.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setWindowTitle("TurboCalendar 3000");
    resize(800,600);
    createCalendar();
    setCentralWidget(calendar);

    createDock();
    createActions();
    createMenus();
    createConnections();

}

void MainWindow::createActions() {

    aboutAct = new QAction("About", this);
    quitAct = new QAction("Quit", this);
    viewContacts = new QAction("Syna kontaktar", this);


}

void MainWindow::createMenus() {

    menu = new QMenuBar(this);
    fileMenu = new QMenu("File", this);
    menu->addMenu(fileMenu);
    fileMenu->addAction(aboutAct);
    fileMenu->addAction(quitAct);
    contactsMenu = new QMenu("Kontakter", this);
    menu->addMenu(contactsMenu);
    contactsMenu->addAction(viewContacts);

    setMenuBar(menu);

}


void MainWindow::createCalendar() {

    calendar = new ExtendedQCalendar();
    calendar->setCurrentWindow(this);

}

void MainWindow::setEventHandler(EventHandler *ehandler) {

    eventHandler=ehandler;

}

void MainWindow::setContactHandler(ContactHandler *chandler) {

    contactHandler=chandler;

}

void MainWindow::createDock() {

    dock = new QDockWidget(tr("Dagens Avtaler"), this);
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures);

    feed = new EventFeed();
    feed->setCurrentWindow(this);

    dock->setWidget(feed);
    feed->show();

    addDockWidget(Qt::RightDockWidgetArea, dock);

}

void MainWindow::createConnections() {

    connect(viewContacts,SIGNAL(triggered()),this,SLOT(showContacts()));
    connect(calendar, SIGNAL(selectionChanged()), this, SLOT(dateClicked()));
    connect(calendar, SIGNAL(clicked(QDate)), this, SLOT(dateClicked(QDate)));

    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

}

void MainWindow::rowDoubleClicked(const QModelIndex &clickedRow) {

    //std::cout << feed->currentRow() << std::endl;

    int row = clickedRow.row();

    Event oldEvent = events.at(row);

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

    delete ev;

}

void MainWindow::dateClicked(QDate date) {

    feed->deactivate();

    if(eventHandler->eventsExists(date)) {

        QDateTime from(date);
        QDateTime to = from.addDays(1);

        events = eventHandler->findEvents(from,to);

        feed->loadEvents(events);

    } else {

        feed->clearEventFeed();

    }

}

void MainWindow::dateClicked() {

    feed->deactivate();

    QDate date(calendar->selectedDate());

    if(eventHandler->eventsExists(date)) {

        QDateTime from(date);
        QDateTime to = from.addDays(1);

        events = eventHandler->findEvents(from,to);

        feed->loadEvents(events);

    } else {

        feed->clearEventFeed();

    }

}

void MainWindow::searchEvent(const EventHandler::QueryArgs& args) {

    events = eventHandler->findEvents(args);

    feed->loadEvents(events);

}

void MainWindow::about() {

    QMessageBox::about(this, "About", "TurboCalendar 3000");

}

void MainWindow::deleteEvent() {

    int index = feed->getActiveEvent();

    eventHandler->removeEvent(events.at(index));
    events.erase(events.begin()+index);
    feed->deactivate();
    feed->loadEvents(events);
    dateClicked();
    calendar->update();
}

void MainWindow::deleteAllEventsToday() {

    for(int eventToDelete=0 ; eventToDelete < (unsigned)events.size() ; eventToDelete ++) {

        eventHandler->removeEvent(events.at(eventToDelete));

    }

    events.clear();
    feed->deactivate();
    feed->clearEventFeed();
    dateClicked();
    calendar->update();

}

void MainWindow::createNewEvent() {

    Event newEvent;

    newEvent.setStartDate(calendar->selectedDate());

    EventView *eventEdit = new EventView();

    eventEdit->setCurrentWindow(this);
    eventEdit->setEvent(newEvent);
    eventEdit->setNewMode();
    eventEdit->exec();

    if(eventEdit->isChanged()){

        newEvent = eventEdit->getEvent();
        eventHandler->addEvent(newEvent);

    }

    delete eventEdit;

    dateClicked();
    calendar->update();

}

void MainWindow::showContacts() {
    ContactView *contacts = new ContactView(contactHandler);
    contacts->exec();
    delete contacts;
}

void MainWindow::show() {

    QWidget::show();

    // Overlasting av base-klassens show for å kunne invoke'e dateClicked-slot'en uten at alt kræsjer(dvs. før konstruktøren er ferdig).

    dateClicked();

}
