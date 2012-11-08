#ifndef CONTACT_H
#define CONTACT_H
#include <string>

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
    int getContId();

    //Setters
    std::string setFname(std::string);
    std::string setLname(std::string);
    int setPhoneNumber(int);
    std::setEmail(std::string);




private:
    std::string fname;
    std::string lname;
    int phoneNumber;
    std::string email;
    int contId;
};

#endif // CONTACT_H
