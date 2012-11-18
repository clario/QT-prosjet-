/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#include "contact.h"

//std Constructor
Contact::Contact(int contactId):
    //parameter list
    fName(""),
    lName(""),
    phoneNumber(NULL),
    email(""),
    cId(contactId)
{}

//If Contact is a firm
Contact::Contact(QString firmName,int contactId, int phoneNum,QString eml) :
    fName(firmName),
    lName(firmName),
    cId(contactId),
    phoneNumber(phoneNum),
    email(eml)
{}
//For Normal contacts with all informastion
Contact::Contact(QString firstName, QString lastName, int contactId, int phoneNum, QString eml):
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

int Contact::getPhoneNumber()
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

void Contact::setPhoneNumber(int phone)
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
bool Contact::operator ==(const Contact &cont)
{

    return (lName.toLower()==cont.lName.toLower() && fName.toLower()==cont.fName.toLower());
}

bool Contact::operator <(const Contact &cont)
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
    temp += QString::number(phoneNumber) + ", ";
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
    return phoneNumber!=NULL;
}

bool Contact::hasEmail()
{
    return !email.isEmpty();
}


























