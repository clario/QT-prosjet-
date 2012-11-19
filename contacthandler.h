/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Lars
  */

#ifndef CONTACTHANDLER_H
#define CONTACTHANDLER_H
#include "contact.h"
#include <QString>
#include <QVector>
#include <QtAlgorithms>

namespace cal {
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
    bool add(QString fName = "", QString lName = "", QString phoneNumber = "", QString email = "");
    /*
     *@param QString fName, QString lName, int phoneNumber, QString email
     *@return Henhaldsvis true/false avhengig av om køyring var vellykka
    */
    bool remove(QString fName, QString lName, QString phoneNumber, QString email);
    /*
     *@param int cID
     *@return Henhaldsvis true/false achenig av om køyringa var velykka
    */
    bool remove(int cID);
    /*
     *@param int nextID
     *@desc Setter ID telleren
    */
    void setCounter(int &nextID);
    /*
     *@desc Setter ID telleren med utganspunkt i høyeste ID + 1
    */
    void setCounter(void);

    /*
     *@desc Returnerer størrelsen på QVectoren brukt for å lagre kontakter
    */
    int getSize(void);


    /*
     * Overloaded operator lets user list
     */
    Contact operator[](int index);

    /*
     * @retrun a QString representation of all the Contacts in container
     */
    QString toString();

    /*
     * Contact save function.
     * Creates a FilWriter object that takes QString savePath as parameter.
     * The FileWriter obj then invoke the save() function and takes the QVector container as param.
     */
    bool save();

    /*
     * Loads a xml file containing Contact data from QDir::CurrentPath() + /contacts.xml
     */
    bool load();

    /*
     *  Uses QSort to sort the Contacts lexicaly based on lName,fName in Contact
     */
    void sort();

    //findContact Methods
    QString findContact(const QString &sf)const;



private:
    QVector<Contact> container;
    int idCounter;
};
#endif // CONTACTHANDLER_H
