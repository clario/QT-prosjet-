/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#include "contacthandler.h"
#include "filewriter.h"
#include <QFile>
#include <QDir>
#include <QDebug>

ContactHandler::ContactHandler(){
    idCounter = 1;
    savePath = QDir::currentPath();
}
ContactHandler::~ContactHandler(){}

bool ContactHandler::add(QString fName, QString lName, int phoneNumber, QString email) {
    Contact *tmp = new Contact(fName, lName, idCounter, phoneNumber, email);
    idCounter++;
    container.push_back(tmp);
    if (tmp==container.last()) {
        return true;
    } else {
        return false;
    }
}

bool ContactHandler::remove(QString fName, QString lName, int phoneNumber, QString email) {
    //Venter med denne til equals(eventuelt == operatorene) i contact er avklart
    return false;
}

bool ContactHandler::remove(int cID) {
    for (int i = 0; i < container.size(); i++) {
        if (*(container[i]) == cID) {
            container.remove(i);
            return true;
        }
    }
    return false;
}

void ContactHandler::setCounter(int &nextID) {
    idCounter=nextID;
}

void ContactHandler::setCounter(void) {
    if (container.size()>0) {
        int max = container[0]->getCId();
        int now = 0;
        for (int i = 1; i < container.size(); i++) {
            now = container[i]->getCId();
            if (now>max) {
                max = now;
            }
        }
        idCounter = max + 1;
    }
}

int ContactHandler::getSize(void) {
    return container.size();
}

Contact *ContactHandler::operator[](int index) {
    return container[index];
}



QString ContactHandler::toString()
{
    QString temp = "";
    foreach(Contact *c,container ){
        temp += c->toString() + "\n";
    }
    return temp;
}



//SAVE FOR HELLVETEIFAEN
bool ContactHandler::save()
{
    FileWriter fw(savePath);
    bool result = fw.save(container);
    return result;
}

