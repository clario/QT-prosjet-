/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#include "contacthandler.h"

//#include <QDebug>

ContactHandler::ContactHandler(){
    idCounter = 1;
}
ContactHandler::~ContactHandler(){}

bool ContactHandler::add(QString fName, QString lName, QString phoneNumber, QString email) {
    int test = container.size();
    container.push_back(Contact(fName,lName,idCounter,phoneNumber,email));

    if(test!=container.size()){
        idCounter++;
        qSort(container);
        return true;
    }else{
        return false;
    }
}

bool ContactHandler::remove(int i) {
    if (!(i < 0 && i >= container.size())) {
        container.remove(i);
        return true;
    } else {
        return false;
    }
}

void ContactHandler::setCounter(void) {
    if (container.size()>0) {
        int max = container[0].getCId();
        int now = 0;
        for (int i = 1; i < container.size(); i++) {
            now = container[i].getCId();
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

Contact& ContactHandler::operator[](int index) {
    return container[index];
}


//TOSTRING
QString ContactHandler::toString()
{
    QString temp = "";
    for(int i = 0; i < container.size(); i++){
        if(i == container.size()-1){
            temp += container[i].toString();
        }else{
            temp += container[i].toString() + '\n';
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

//LOAD
bool ContactHandler::load()
{
    container.clear();
    QString source = QDir::currentPath();
    source += "/contacts.xml";
    FileHandler fr(source);
    bool result = fr.load(container);
    setCounter();
    qSort(container);
    return result;
}

//SORT THE CONTAINER
void ContactHandler::sort()
{
    qSort(container);
}



