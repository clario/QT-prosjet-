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
     *@param int i
     *@return Henhaldsvis true/false avhengig av om elementet eksisterte
    */
    bool remove(int i) {
        if (!(i > 0 && i < container.size())) {
            container.remove(i);
            return true;
        } else {
            return false;
        }
    }

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
    Contact& operator[](int index);

    /*
     * @retrun a QString representation of all the Contacts in container
     */
    QString toString();

    /*
     * @desc Stores the content of the vector in XML form in QDir::CurrentPath() + /contacts.xml
     */
    bool save();

    /*
     * @desc Loads a xml file containing Contact data from QDir::CurrentPath() + /contacts.xml
     *       Contacts are sorted after they have been loaded
     */
    bool load();

    /*
     * @desc Uses QSort to sort the Contacts lexicaly based on lName,fName in Contact
     */
    void sort();

private:
    QVector<Contact> container;
    int idCounter;
};
#endif // CONTACTHANDLER_H
