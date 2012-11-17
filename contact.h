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
    Contact(int contactId);
    Contact(QString firmName,int contactId, int phoneNum,QString eml);
    Contact(QString firstName, QString lastName, int contactId, int phoneNum, QString eml);
    ~Contact();

    //getters
    QString getFName();
    QString getLName();
    int getPhoneNumber();
    QString getEmail();
    int getCId();

    //Setters
    void setFName(QString firstName);
    void setLName(QString lastName);
    void setPhoneNumber(int phone);
    void setEmail(QString);
    //Fjernes når ferdig
    void setCId(int contactId);

    //Methods to be continued...
    bool operator==(const Contact &contact);

    QString toString();

private:
    QString fName;
    QString lName;
    int phoneNumber;
    QString email;
    int cId;
};

#endif // CONTACT_H
