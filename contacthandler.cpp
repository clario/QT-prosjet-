/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#include "contacthandler.h"

ContactHandler::ContactHandler()
{
}

bool ContactHandler::add(string fName, string lName, int phoneNumber, string email) {
    Contact *tmp = new Contact(fName, lName, idCounter, phoneNumber, email);
    idCounter++;
    container.push_back(tmp);
    if (tmp==container.last()) {
        return true;
    } else {
        return false;
    }
}

bool ContactHandler::remove(string fName, string lName, int phoneNumber, string email) {
    //Venter med denne til equals(eventuelt == operatorene) i contact er avklart
}

bool ContactHandler::remove(int cID) {
    //Venter med denne til equals(eventuelt == operatorene) i contact er avklart
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
