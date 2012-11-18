#include "troller.h"
#include "eventhandler.h"
#include "contacthandler.h"
#include "mainwindow.h"

Troller::Troller()
{

    ContactHandler contactHandler;
    EventHandler eventHandler;
    MainWindow mainWindow;
    mainWindow.setEventHandler(&eventHandler);
    mainWindow.setContactHandler(&contactHandler);

    mainWindow.show();

}


