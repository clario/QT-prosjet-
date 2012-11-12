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
    Contact(int);
    Contact(string,int,int,string);
    Contact(string,string,int,int,string);
    ~Contact();

    //getters
    string getFName();
    string getLName();
    int getPhoneNumber();
    string getEmail();
    int getCId();

    //Setters
    void setFName(string);
    void setLName(string);
    void setPhoneNumber(int);
    void setEmail(string);
    //Fjernes når ferdig
    void setCId();

    //Methods to be continued...


private:
    string fName;
    string lName;
    int phoneNumber;
    string email;
    int cId;
};

#endif // CONTACT_H
