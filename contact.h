/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#ifndef CONTACT_H
#define CONTACT_H
#include <QString>

/**
  * Denne klassen skal bare inneholde innformasjon om en og bare en kontakt
  */
using namespace std;

//Declaring calendar namespace
namespace calendar{
    class Contact;
}



class Contact
{
public:
    Contact(int contactId);
    Contact(string firmName,int contactId, int phoneNum,string eml);
    Contact(string firstName, string lastName, int contactId, int phoneNum, string eml);
    ~Contact();

    //getters
    string getFName();
    string getLName();
    int getPhoneNumber();
    string getEmail();
    int getCId();

    //Setters
    void setFName(string firstName);
    void setLName(string lastName);
    void setPhoneNumber(int phone);
    void setEmail(string);
    //Fjernes når ferdig
    void setCId(int contactId);

    //Methods to be continued...
    bool operator==(const Contact &contact);

private:
    string fName;
    string lName;
    int phoneNumber;
    string email;
    int cId;
};

#endif // CONTACT_H
