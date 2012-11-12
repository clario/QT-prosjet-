/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#include "contacthandler.h"

ContactHandler::ContactHandler()
{
}

bool ContactHandler::add(string fName, string lName, int phoneNumber, string email) {
    Contact *tmp = Contact(idCounter, fName, lName, phoneNumber, email);
    idCounter++;
    container.push_back(tmp);
    if (tmp==container.end()) {
        return true;
    } else {
        return false;
    }
}

bool ContactHandler::remove(string fName, string lName, int phoneNumber, string email) {
    //Venter med denne til søkemetodene i contact er avklart
}

bool ContactHandler::remove(int cID) {
    //Venter på ein metode for å fjekke ein kontakt mot ein anna kontakt sin cID
}

void ContactHandler::setCounter(int &nextID) {
    idCounter=nextID;
}

void ContactHandler::setCounter(void) {
    //Venter litt med denne
}

int ContactHandler::getSize(void) {
    return container.size();
}
