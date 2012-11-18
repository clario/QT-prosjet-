/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#include "contacthandler.h"
#include "filehandler.h"
#include <QFile>
#include <QDir>
#include <QtAlgorithms>
#include <QDebug>

ContactHandler::ContactHandler(){
    idCounter = 1;
}
ContactHandler::~ContactHandler(){}

bool ContactHandler::add(QString fName, QString lName, int phoneNumber, QString email) {
    Contact *tmp = new Contact(idCounter);
    idCounter++;
    if(fName!=""){
        tmp->setFName(fName);
    }
    if(lName!=""){
        tmp->setLName(lName);
    }
    if(phoneNumber!=NULL){
        tmp->setPhoneNumber(phoneNumber);
    }
    if(email!=""){
        tmp->setEmail(email);
    }
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
        if (container[i]!=NULL && container[i]->getCId() == cID) {
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
    for(int i = 0; i < container.size(); i++){
        if(i == container.size()-1){
            temp += container.at(i)->toString();
        }else{
            temp += container.at(i)->toString() + '\n';
        }
    }
    return temp;
}



//SAVE
bool ContactHandler::save()
{
    QString savePath = QDir::currentPath();
    savePath += QString("/contacts.xml");
    FileHandler fh(savePath);
    bool result = fh.save(container);
    return result;
}

void ContactHandler::sort()
{
    qSort(container.begin(),container.end());
}


