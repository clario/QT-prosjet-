#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <vector>
#include <event.h>
/**
  * Navnet indikerer funksjon så den handler altså eventene
  */
using namespace std;

//Declaring calendar namespace
namespace calendar{
    class Contact;
}


class EventHandler
{
public:
    EventHandler();
    ~EventHandler();

    /**
      * Finner event
      */
    Event findEvent();

    //Mulige implementeringer
    void addEvent();
    Event removeEvent();


private:
    //Container type kan diskuteres
    vector<Event> eventContainer;
    vector<string> eventTypes; //<- Vist vi går for det her er eventType i praksis distinkt og case sensitive/insensitive (kan sjekkast i logikk laget)


};

#endif // EVENTHANDLER_H
