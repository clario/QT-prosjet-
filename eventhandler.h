#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <vector>
#include <event.h>
/**
  * Navnet indikerer funksjon så den handler altså eventene
  */

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
    std::vector eventContainer;


};

#endif // EVENTHANDLER_H
