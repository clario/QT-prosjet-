#ifndef CONTACTHANDLER_H
#define CONTACTHANDLER_H
#include <contact.h>;
#include <string>;

//Bygger berre opp klassene med metoder. Venter med implementasjon til det er nødvendig
//Tenkte det kunne være greit med eit førebels interface å jobbe etter ;)

namespace calender {
    class ContactHandler;
}

class ContactHandler
{
public:
    ContactHandler();
    ~ContactHandler();

    bool add(void);
    bool remove(void);
    int find(string); //søker etter match i fornavn og etternavn, returnerer plassering i tabellen
    int find(int); //søker etter telefonnummer, returnerer plassering i tabellen

    //Finn metodane eg har laga er muligens ikkje idelle. Er berre mockup

private:
    contact array[]; //Antar at vi endrer datastruktur her seinare.
    int size;
};
#endif // CONTACTHANDLER_H
