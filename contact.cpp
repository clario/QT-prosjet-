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
Contact::Contact(string firmName,int contactId, int phoneNum,string eml) :
    fName(firmName),
    lName(firmName),
    cId(contactId),
    phoneNumber(phoneNum),
    email(eml)
{}
//For Normal contacts with all informastion
Contact::Contact(string firstName, string lastName, int contactId, int phoneNum, string eml):
    fName(firstName),
    lName(lastName),
    cId(contactId),
    phoneNumber(phoneNum),
    email(eml)
{}

//Getters
string Contact::getFName()
{
    return fName;
}

string Contact::getLName()
{
    return lName;
}

int Contact::getPhoneNumber()
{
    return phoneNumber;
}

string Contact::getEmail()
{
    return email;
}

int Contact::getCId()
{
    return cId;
}

//Setters
void Contact::setFName(string firstName)
{
    fName=firstName;
}

void Contact::setLName(string lastName)
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















