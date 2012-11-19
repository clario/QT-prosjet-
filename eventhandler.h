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

    /**
     * En klasse for å enkelt spesifisere hvilke krav events skal tilfredsstille under et søk.
     * Siden vi bruker Qt typer kan vi enkelt bruke metoder for å sjekke
     * verdiene er satt (eks. om en streng er tom eller en dato er satt)
     */
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

    /**
     * Hjelpemetoder for å finne ut om der finnes events mellom datoer eller på en dato
     */
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

    /**
     * Iteratorer som kan brukes ved serialisering eller ren iterering
     */
    const_iterator begin() const;
    const_iterator end() const;

    void addEvent(const Event& event);
    bool removeEvent(const Event& event);

    unsigned int count() const;

    void save();// Lagrer til /sti/til/appmappa/events.xml
    void load();// Laster fra /sti/til/appmappa/events.xml

private:
    //Container type kan diskuteres
    std::set<Event> eventContainer; // Denne er ferdigsortert for datoer
};

Q_DECLARE_METATYPE(EventHandler::QueryArgs);

#endif // EVENTHANDLER_H
