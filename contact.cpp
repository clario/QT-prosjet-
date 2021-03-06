/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#include "contact.h"
Contact::Contact():
    cId(NULL),
    fName(""),
    lName(""),
    phoneNumber(""),
    email("")
{}

Contact::Contact(int contactId):
    cId(contactId),
    fName(""),
    lName(""),
    phoneNumber(""),
    email("")
{}

//For Normal contacts with all informastion
Contact::Contact(QString firstName, QString lastName, int contactId, QString phoneNum, QString eml):
    fName(firstName),
    lName(lastName),
    cId(contactId),
    phoneNumber(phoneNum),
    email(eml)
{}

Contact::~Contact()
{
}

//Getters
QString Contact::getFName()
{
    return fName;
}

QString Contact::getLName()
{
    return lName;
}

QString Contact::getPhoneNumber()
{
    return phoneNumber;
}

QString Contact::getEmail()
{
    return email;
}

int Contact::getCId()
{
    return cId;
}

//Setters
void Contact::setFName(QString firstName)
{
    fName=firstName;
}

void Contact::setLName(QString lastName)
{
    lName=lastName;
}

void Contact::setPhoneNumber(QString phone)
{
    phoneNumber=phone;
}

void Contact::setEmail(QString eMail)
{
    email=eMail;
}

void Contact::setCId(int contactId)
{
    cId=contactId;
}

//overloaded operators
bool Contact::operator ==(const Contact &cont) const
{

    return (lName.toLower()==cont.lName.toLower() && fName.toLower()==cont.fName.toLower());
}

bool Contact::operator <(const Contact &cont)const
{
    if(lName.toLower() == cont.lName.toLower()){
        return (fName.toLower() < cont.fName.toLower());
    }else{
        return (lName.toLower() < cont.lName.toLower());
    }
}


//QString representation of contact
QString Contact::toString()
{
    QString temp = "";

    temp += lName + ", ";
    temp += fName + ", ";
    temp += phoneNumber + ", ";
    temp += email + ",";
    temp += QString::number(cId);

    return temp;
}


int Contact::compare(Contact &cont)
{
    if(operator <(cont)){
        return -1;
    }else if (operator ==(cont)) {
        return 0;
    }else{
        return 1;
    }
}

// has functions
bool Contact::hasFName()
{
    return !fName.isEmpty();
}

bool Contact::hasLName()
{
    return !lName.isEmpty();
}

bool Contact::hasPhoneNumber()
{
    return !phoneNumber.isEmpty();
}

bool Contact::hasEmail()
{
    return !email.isEmpty();
}




























