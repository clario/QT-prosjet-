/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <vector>

#include <QDateTime>
#include <QDate>
#include <QTime>

#include "contact.h"

namespace calendar {

class Event
{
public:
    Event();

    QString getTitle() const;
    void setTitle(const QString& title);

    /**
     * Metoder for startdato
     */

    QDateTime getStartDateTime() const;
    bool setStartDateTime(const QDateTime& startDateTime);

    /**
     * Returnerer en tidsstreng på formatet 2012-02-01T22:33:00
     */
    QString getStartAsString() const;

    /**
     * Denne er grei å bruke for å laste 
     * nn dato fra et serialisert objkt
     * Krever formatet 2012-02-01T22:33:00
     */
    bool setStartAsString(const QString& start);

    QDate getStartDate() const;
    bool setStartDate(const QDate& startDate);

    QTime getStartTime() const;
    bool setStartTime(const QTime& startTime);

    /**
     * Metoder for sluttdato
     **/

    QDateTime getEndDateTime() const;
    bool setEndDateTime(const QDateTime& endDateTime);

    /**
     * Returnerer en tidsstreng på formatet 2012-02-01T22:33:00
     */
    QString getEndAsString() const;

    /**
     * Denne er grei å bruke for å laste 
     * nn dato fra et serialisert objkt
     * Krever formatet 2012-02-01T22:33:00
     */
    bool setEndAsString(const QString& start);


    QDate getEndDate() const;
    bool setEndDate(const QDate& endDate);

    QTime getEndTime() const;
    bool setEndTime(const QTime& endTime);

    std::vector<QString> getParticipants() const;
    void setParticipants(std::vector<QString> participants);

    bool operator== (const Event& other) const;

    static const QString dateTimeFormat;

private:
    QString title;
    QString eventType;
    QString location;

    QDateTime start;
    QDateTime end;

    std::vector<QString> participants;
};

}; // End namespace calendar
#endif // EVENT_H
