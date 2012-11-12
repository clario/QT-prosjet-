/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#ifndef CONTACT_H
#define CONTACT_H
#include <string>

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
    string getFname();
    string getLname();
    int getPhoneNumber();
    string getEmail();
    int getCId();

    //Setters
    void setFname(string);
    void setLname(string);
    void setPhoneNumber(int);
    void setEmail(string);
    void setCId();

    //Methods to be continued...


private:
    string fname;
    string lname;
    int phoneNumber;
    string email;
    int cId;
};

#endif // CONTACT_H
