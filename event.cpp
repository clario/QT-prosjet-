/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#include "event.h"

const QString Event::dateTimeFormat = "yyyy-MM-ddThh:mm:ss";

/**
 * Oppretter et tomt objekt med defaultverdier
 */
Event::Event()
{
    title = "";
    description = "";
    location = "";
    eventType = "";
    repeats = 0;
    absence = false;
    setStartDateTime(QDateTime::currentDateTime());
}

/**
 * Kopikonstruktør
 */
Event::Event(const Event& original) {
    title = original.getTitle();
    description = original.getDescription();
    location = original.getLocation();
    eventType = original.getEventType();
    repeats = original.getRepeats();
    start = original.getStartDateTime();
    end = original.getEndDateTime();
    absence = original.getAbsence();
}

/** Title getters og setters **/
QString Event::getTitle() const {
    return title;
}

bool Event::hasTitle() const {
    return !title.isEmpty();
}

void Event::setTitle(const QString& _title) {
    title = _title;
}

/** Description getters og setters **/
QString Event::getDescription() const {
    return description;
}

bool Event::hasDescription() const {
    return !description.isEmpty();
}

void Event::setDescription(const QString& _description) {
    description = _description;
}

/** EventType getters og setters **/
QString Event::getEventType() const {
    return eventType;
}

bool Event::hasEventType() const {
    return !eventType.isEmpty();
}

void Event::setEventType(const QString& _eventType) {
    eventType = _eventType;
}

/** Absence getters og setters **/
bool Event::getAbsence() const {
    return absence;
}

bool Event::hasAbsence() const {
    return absence;
}

void Event::setAbsence(bool _absence) {
    absence = _absence;
}

/** Location getters og setters **/
QString Event::getLocation() const {
    return location;
}

bool Event::hasLocation() const {
    return !location.isEmpty();
}

void Event::setLocation(const QString& _location) {
    location = _location;
}

/**
  * Metoder for startdato
  **/
QDateTime Event::getStartDateTime() const {
    return start;
}

bool Event::setStartDateTime(const QDateTime& startDateTime) {
    start = startDateTime;
    if (!end.isValid() || end < start) { // Sett sluttdato hvis sluttdato ikke er satt eller kommer før startdato
        end = startDateTime.addSecs(60*60);
    }
    return true;
}

/**
  * Returnerer en tidsstreng på formatet 2012-02-01T22:33:00, dateTimeFormat er en statisk klassekonstant
  */
QString Event::getStartAsString() const {
    return start.toString(dateTimeFormat);
}

/**
  * Denne er grei å bruke for å laste
  * en dato fra et serialisert objekt
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

/** Participant getters og setters **/
std::vector<QString> Event::getParticipants() const {
    return std::vector<QString>();
}

void Event::setParticipants(const std::vector<QString>& _participants) {
   participants = _participants;
}

void Event::addParticipant(const QString& participant) {
    participants.push_back(participant);
}

/** Sammenligningsoperatorer **/
bool Event::operator==(const Event& other) const {
    bool equal = (title == other.getTitle());

    if (equal) {
        equal = (description == other.getDescription());
    }

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

/** Repeat getters og setters **/
unsigned int Event::getRepeats() const {
    return repeats;
}

void Event::setRepeats(unsigned int _repeats) {
    repeats = repeats;
}
