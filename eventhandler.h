/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <vector>
#include <set>

#include "event.h"

namespace calendar{

class EventHandler
{
public:
    EventHandler();
    ~EventHandler();

    typedef std::set<Event>::const_iterator const_iterator;

    /**
      * Finner events
      */
    std::vector<Event> findEvents(const QDateTime& from, const QDateTime& to) const;

    /**
     * Returnerer alle events
     */
    std::vector<Event> getAll() const;

    const_iterator begin() const;
    const_iterator end() const;

    //Mulige implementeringer
    void addEvent(const Event& event);
    bool removeEvent(const Event& event);

    unsigned int count() const;

private:
    //Container type kan diskuteres
    std::set<Event> eventContainer; // Denne er ferdigsortert for datoer
    std::vector<std::string> eventTypes; //<- Vist vi går for det her er eventType i praksis distinkt og case sensitive/insensitive (kan sjekkast i logikk laget)


};

}; // End namespace calendar

#endif // EVENTHANDLER_H
