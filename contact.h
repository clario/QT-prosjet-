#ifndef CONTACT_H
#define CONTACT_H
#include <string>

/**
  * Denne klassen skal bare inneholde innformasjon om en og bare en kontakt
  */

//Declaring calendar namespace
namespace calendar{
    class Contact;
}



class Contact
{
public:
    Contact();
    Contact(std::string,int,std::string);
    Contact(std::string,std::string,int,std::string);
    ~Contact();

    //getters
    std::string getFname();
    std::string getLname();
    int getPhoneNumber();
    std::string getEmail();
    int getCId();

    //Setters
    void setFname(std::string);
    void setLname(std::string);
    void setPhoneNumber(int);
    void setEmail(std::string);
    void setCId();

    //Methods to be continued...


private:
    std::string fname;
    std::string lname;
    int phoneNumber;
    std::string email;
    int cId;
};

#endif // CONTACT_H
