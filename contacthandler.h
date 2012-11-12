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

    bool add();
    bool remove(void);

private:
    QVector container; //Antar at vi endrer datastruktur her seinare.
    int size;
    int idCounter;
};
#endif // CONTACTHANDLER_H
