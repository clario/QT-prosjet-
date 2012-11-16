/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#include "event.h"

using namespace calendar;

const QString Event::dateTimeFormat = "yyyy-MM-ddThh:mm:ss";

Event::Event()
{
    location = "";
    repeats = 0;
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
    if (!end.isValid()) { // Hvis sluttdato ikke er satt
        end = startDateTime;
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
    start = QDateTime::fromString(startDateTime, dateTimeFormat);
    return true;
}

QDate Event::getStartDate() const {
    return start.date();
}

bool Event::setStartDate(const QDate& startDate) {
    start.setDate(startDate);
    return true;
}

QTime Event::getStartTime() const {
    return start.time();
}

bool Event::setStartTime(const QTime& startTime) {
    start.setTime(startTime);
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
    if (!start.isValid()) { // Hvis startdato ikke er satt
        start = endDateTime;
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
    end = QDateTime::fromString(endDateTime, dateTimeFormat);
    return true;
}


QDate Event::getEndDate() const {
    return end.date();
}

bool Event::setEndDate(const QDate& endDate) {
    end.setDate(endDate);
    return true;
}

QTime Event::getEndTime() const {
    return end.time();
}

bool Event::setEndTime(const QTime& endTime) {
    end.setTime(endTime);
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

    return lessThan;
}

unsigned int Event::getRepeats() const {
    return repeats;
}

void Event::setRepeats(unsigned int _repeats) {
    repeats = repeats;
}
