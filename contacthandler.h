/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#ifndef CONTACTHANDLER_H
#define CONTACTHANDLER_H
#include <contact.h>;
#include <QString>;
#include <QVector>;

namespace calender {
    class ContactHandler;
}

class ContactHandler
{
public:
    ContactHandler();
    ~ContactHandler();

    /*
     *@param QString fName, QString lName, int phoneNumber, QString email
     *@return Henhaldsvis true/false avhengig av om køyring var vellykka
    */
    bool add(string fName, string lName, int phoneNumber, string email);
    /*
     *@param QString fName, QString lName, int phoneNumber, QString email
     *@return Henhaldsvis true/false avhengig av om køyring var vellykka
    */
    bool remove(string fName, string lName, int phoneNumber, string email);
    /*
     *@param int cID
     *@return Henhaldsvis true/false achenig av om køyringa var velykka
    */
    bool remove(int cID);
    /*
     *@param int nextID
     *@desc Setter ID telleren
    */
    void setCounter(int nextID);
    /*
     *@desc Setter ID telleren med utganspunkt i høyeste ID + 1
    */
    void setCounter();

private:
    QVector container;
    int size;
    int idCounter;
};
#endif // CONTACTHANDLER_H
