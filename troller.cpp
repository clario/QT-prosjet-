#include "troller.h"

Troller::Troller()
{

    mainwindow = new MainWindow();
    mainwindow->setContactHandler(&chandler);
    mainwindow->setEventHandler(&ehandler);

}

void Troller::run() {

    mainwindow->show();

}
