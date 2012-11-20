#include <QtGui/QApplication>
#include "troller.h"
#include "calendarview.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Troller calendar;
    calendar.run();

    //app.setActiveWindow(&calendar.mainWindow);

    int retVal = app.exec();
    calendar.hasClosed();

    return retVal;
}





