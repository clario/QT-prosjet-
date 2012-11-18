#ifndef TROLLER_H
#define TROLLER_H
#include <QDebug>
#include "mainwindow.h"
#include "contacthandler.h"
#include "eventhandler.h"

class MainWindow;

class Troller
{
public:
    Troller();

    void run();

    MainWindow *mainwindow;
    ContactHandler chandler;
    EventHandler ehandler;

private:

};

#endif // TROLLER_H
