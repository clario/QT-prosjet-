#include "troller.h"
#include "eventhandler.h"
#include "contacthandler.h"
#include "mainwindow.h"
#include "event.h"
#include <QDebug>

Troller::Troller(QObject *parent) :
    QObject(parent)
{

    mainWindow.setEventHandler(&eventHandler);
    mainWindow.setContactHandler(&contactHandler);

   eventHandler.load();
   contactHandler.load();

}

void Troller::run() {

     mainWindow.show();

}

void Troller::hasClosed() {

    eventHandler.save();
    contactHandler.save();
    qDebug("Lagra!");

}


// La troller arve qobject og lag en slot som invoker save i event og contacthandler ved mainwindow.closed().
