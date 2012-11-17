/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#include "contact.h"

//std Constructor
Contact::Contact(int contactId):
    //parameter list
    fName("not set"),
    lName("not set"),
    phoneNumber(000),
    email("prefix@placeholder.ru"),
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

void Contact::setCId(int contactId)
{
    cId=contactId;
}

//overloaded operators
bool Contact::operator ==(const Contact &contact)
{
    return cId==contact.cId;
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

















