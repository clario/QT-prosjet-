#include "troller.h"
#include "eventhandler.h"
#include "contacthandler.h"
#include "mainwindow.h"
#include "event.h"

Troller::Troller()
{

    mainWindow.setEventHandler(&eventHandler);
    mainWindow.setContactHandler(&contactHandler);

    Event test;
    test.setStartDate(QDate::currentDate());
    test.setEndDate(QDate(2012,11,21));

    test.setTitle("Brazilian Waxing");

    eventHandler.addEvent(test);

    mainWindow.show();

}


