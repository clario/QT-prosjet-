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




