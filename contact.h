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


class Contact
{
public:
    Contact();
    Contact(int contactId);
    Contact(QString firstName, QString lastName, int contactId, QString phoneNum, QString eml);
    ~Contact();

    //getters
    QString getFName();
    QString getLName();
    QString getPhoneNumber();
    QString getEmail();
    int getCId();

    //Setters
    void setFName(QString firstName);
    void setLName(QString lastName);
    void setPhoneNumber(QString phone);
    void setEmail(QString eMail);
    //Fjernes når ferdig
    void setCId(int contactId);


    //Has functions
    bool hasFName();
    bool hasLName();
    bool hasPhoneNumber();
    bool hasEmail();



    //Methods to be continued...
    bool operator ==(const Contact &cont)const;
    bool operator !=(const Contact & cont)const{return !(*this==cont);}
    bool operator <(const Contact &cont)const;
    bool operator >=(const Contact &cont)const{return !(*this<cont);}



    QString toString();

    int compare(Contact &cont);

    void qsort();


private:
    QString fName;
    QString lName;
    QString phoneNumber;
    QString email;
    int cId;
};

#endif // CONTACT_H
