#ifndef TROLLER_H
#define TROLLER_H
#include <QDebug>
#include "eventhandler.h"
#include "contacthandler.h"
#include "mainwindow.h"

class Troller
{
public:
    Troller();

private:

    MainWindow mainWindow;
    EventHandler eventHandler;
    ContactHandler contactHandler;


};

#endif // TROLLER_H
