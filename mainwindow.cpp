#include "mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    setWindowTitle("TurboCalendar 3000");
    resize(800,600);

    createCalendar();
    //setCentralWidget(calendar);

    //createDock();

    setCentralWidget(calendar);

}

void MainWindow::setEventHandler(EventHandler *ehandler)
{

    eventHandler=ehandler;

}

void MainWindow::setContactHandler(ContactHandler *chandler)
{

    contactHandler=chandler;

}

void MainWindow::createDock()
{
    /*
    dock = new QDockWidget("Dagens gjøremål", this);
    dock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    dock->setAllowedAreas(Qt::RightDockWidgetArea);

    //QPushButton *demo = new QPushButton("Blargh");
    dock->setWidget(feed);
    */
}

void MainWindow::createCalendar()
{

    calendar = new CalendarView();

}


