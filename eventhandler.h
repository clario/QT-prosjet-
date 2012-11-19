/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <vector>
#include <set>

#include "event.h"


class EventHandler
{
public:
    EventHandler();
    ~EventHandler();

    typedef std::set<Event>::const_iterator const_iterator;

    class QueryArgs {
        public:
        QDateTime from;
        QDateTime to;
        QString title;
        QString description;
        QString participant;
        QString eventType;
        QString location;
    };

    /**
      * Finner events
      */
    std::vector<Event> findEvents(const QDateTime& from, const QDateTime& to) const;

    /**
     * Eksempelspørring:
     * EventHandler::QueryArgs q;
     * q.from = QDateTime()::currentDateTime();
     * q.to = QDateTime()::currentDateTime().addDays(3);
     * q.title = "a";
     */
    std::vector<Event> findEvents(const EventHandler::QueryArgs& queryArgs) const;

    bool eventsExists(const QDateTime& from, const QDateTime& to) const;
    bool eventsExists(const QDate& from) const;

    /**
     * Vil finne elementet som er _nøyaktig_ lik oldEvent (via operator==) og erstatte det med newEvent.
     * Kjekk å bruke via andre grensesnitt som et GUI.
     */
    bool replace(const Event& oldEvent, const Event& newEvent);

    /**
     * Returnerer alle events, ikke anbefalt å bruke
     */
    std::vector<Event> getAll() const;

    const_iterator begin() const;
    const_iterator end() const;

    //Mulige implementeringer
    void addEvent(const Event& event);
    bool removeEvent(const Event& event);

    unsigned int count() const;

    void save();// Lagrer til /sti/til/appmappa/events.xml
    void load();// Laster fra /sti/til/appmappa/events.xml

private:
    //Container type kan diskuteres
    std::set<Event> eventContainer; // Denne er ferdigsortert for datoer
    std::vector<std::string> eventTypes; //<- Vist vi går for det her er eventType i praksis distinkt og case sensitive/insensitive (kan sjekkast i logikk laget)


};

#endif // EVENTHANDLER_H
