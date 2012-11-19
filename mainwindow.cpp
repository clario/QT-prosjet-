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

}

void MainWindow::createActions() {

    aboutAct = new QAction("About", this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    quitAct = new QAction("Quit", this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(close()));

}

void MainWindow::createMenus() {

    menu = new QMenuBar();
    fileMenu = new QMenu("File");
    menu->addMenu(fileMenu);
    fileMenu->addAction(aboutAct);
    fileMenu->addAction(quitAct);

    setMenuBar(menu);

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

void MainWindow::createDock() {

    dock = new QDockWidget(tr("Dagens Avtaler"), this);
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures);

    feed = new EventFeed();
    feed->setCurrentWindow(this);

    dock->setWidget(feed);
    feed->show();

    addDockWidget(Qt::RightDockWidgetArea, dock);

}

void MainWindow::rowClicked(QModelIndex clickedRow) {

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


}

void MainWindow::dateClicked(QDate date) {

    if(eventHandler->eventsExists(date)) {

        QDateTime from(date);
        QDateTime to = from.addDays(1);

        events = eventHandler->findEvents(from,to);

        feed->loadEvents(events);

    }

}

void MainWindow::about() {

    QMessageBox::about(this, "About", "TurboCalendar 3000");

}
