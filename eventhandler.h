/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <vector>

#include "event.h"

namespace calendar{

class EventHandler
{
public:
    EventHandler();
    ~EventHandler();

    /**
      * Finner event
      */
    std::vector<Event> findEvents(const QDate& from, const QDate& to) const;

    /**
     * Returnerer alle events
     */
    std::vector<Event> getAll() const;

    //Mulige implementeringer
    void addEvent(const Event& event);
    Event removeEvent(const Event& event);


private:
    //Container type kan diskuteres
    vector<Event> eventContainer;
    vector<std::string> eventTypes; //<- Vist vi går for det her er eventType i praksis distinkt og case sensitive/insensitive (kan sjekkast i logikk laget)


};

}; // End namespace calendar

#endif // EVENTHANDLER_H
