#include "mainwindow.h"

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

}

void MainWindow::setEventHandler(EventHandler *ehandler) {

    eventHandler=ehandler;

}

void MainWindow::setContactHandler(ContactHandler *chandler) {

    contactHandler=chandler;

}
