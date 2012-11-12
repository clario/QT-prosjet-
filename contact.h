/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#ifndef CONTACT_H
#define CONTACT_H
#include <Qstring>

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
    Contact();
    Contact(string,int,string);
    Contact(string,string,int,string);
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
