/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#include "event.h"

using namespace calendar;

const QString Event::dateTimeFormat = "yyyy-MM-ddThh:mm:ss";

Event::Event()
{
    title = "";
    location = "";
    eventType = "";
    repeats = 0;
    setStartDateTime(QDateTime::currentDateTime());
}

QString Event::getTitle() const {
    return title;
}

void Event::setTitle(const QString& _title) {
    title = _title;
}

QString Event::getLocation() const {
    return location;
}

void Event::setLocation(const QString& _location) {
    location = _location;
}

QDateTime Event::getStartDateTime() const {
    return start;
}

bool Event::setStartDateTime(const QDateTime& startDateTime) {
    start = startDateTime;
    if (!end.isValid() || end < start) { // Sett sluttdato hvis sluttdato er før startdato
        end = startDateTime.addSecs(60*60);
    }
    return true;
}

/**
  * Returnerer en tidsstreng på formatet 2012-02-01T22:33:00
  */
QString Event::getStartAsString() const {
    return start.toString(dateTimeFormat);
}

/**
  * Denne er grei å bruke for å laste
  * nn dato fra et serialisert objkt
  * Krever formatet 2012-02-01T22:33:00
  */
bool Event::setStartAsString(const QString& startDateTime) {
    setStartDateTime(QDateTime::fromString(startDateTime, dateTimeFormat));
    return true;
}

QDate Event::getStartDate() const {
    return start.date();
}

bool Event::setStartDate(const QDate& startDate) {
    setStartDateTime(QDateTime(startDate, start.time()));
    return true;
}

QTime Event::getStartTime() const {
    return start.time();
}

bool Event::setStartTime(const QTime& startTime) {
    setStartDateTime(QDateTime(start.date(), startTime));
    return true;
}

/**
  * Metoder for sluttdato
  **/

QDateTime Event::getEndDateTime() const {
    return end;
}

bool Event::setEndDateTime(const QDateTime& endDateTime) {
    end = endDateTime;
    if (end < start) { // Sett startdato hvis startdato blir etter slutt
        start = endDateTime.addSecs(60*60);
    }
    return true;
}

/**
  * Returnerer en tidsstreng på formatet 2012-02-01T22:33:00
  */
QString Event::getEndAsString() const {
    return end.toString(dateTimeFormat);
}

/**
  * Denne er grei å bruke for å laste 
  * nn dato fra et serialisert objkt
  * Krever formatet 2012-02-01T22:33:00
  */
bool Event::setEndAsString(const QString& endDateTime) {
    setEndDateTime(QDateTime::fromString(endDateTime, dateTimeFormat));
    return true;
}


QDate Event::getEndDate() const {
    return end.date();
}

bool Event::setEndDate(const QDate& endDate) {
    setEndDateTime(QDateTime(endDate, end.time()));
    return true;
}

QTime Event::getEndTime() const {
    return end.time();
}

bool Event::setEndTime(const QTime& endTime) {
    setEndDateTime(QDateTime(end.date(), endTime));
    return true;
}

std::vector<QString> Event::getParticipants() const {
    return std::vector<QString>();
}

void Event::setParticipants(std::vector<QString> _participants) {
   participants = _participants;
}

bool Event::operator==(const Event& other) const {
    bool equal = (title == other.getTitle());

    if (equal) {
        equal = (start == other.getStartDateTime());
    }
    
    if (equal) {
        equal = (end == other.getEndDateTime());
    }

    if (equal) {
        equal = (participants == other.getParticipants());
    }

    return equal;
}

bool Event::operator<(const Event& other) const {
    bool lessThan = (start < other.getStartDateTime());

    if (!lessThan && (start == other.getStartDateTime())) {
        lessThan = (end < other.getEndDateTime());
    }

    if (!lessThan && (end == other.getEndDateTime())) {
        lessThan = (title.compare(other.getTitle()) < 0);
    }

    return lessThan;
}

unsigned int Event::getRepeats() const {
    return repeats;
}

void Event::setRepeats(unsigned int _repeats) {
    repeats = repeats;
}
