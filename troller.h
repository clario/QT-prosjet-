#ifndef TROLLER_H
#define TROLLER_H
#include <QDebug>
#include <QObject>
#include <QApplication>
#include "eventhandler.h"
#include "contacthandler.h"
#include "mainwindow.h"

class Troller : public QObject
{
public:
    Troller(QObject *parent = 0);

    void run();

private:

    MainWindow mainWindow;
    EventHandler eventHandler;
    ContactHandler contactHandler;

public slots:

    void hasClosed();

};

#endif // TROLLER_H
