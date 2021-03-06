/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#include <QDebug>
#include <QDir>

#include "eventhandler.h"
#include "filehandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler() {

}

std::vector<Event> EventHandler::findEvents(const QDateTime& from, const QDateTime& to) const {
	// Denne metoden finner alle events mellom to datoer. søket er inklusivt.
	// Det finner ALLE events som starter, slutter eller pågår innenfor et tidsrom.
	std::vector<Event> results;
	EventHandler::const_iterator it, it_end;

	Event toEvent;
	toEvent.setStartDateTime(to);
	it_end = eventContainer.upper_bound(toEvent);
	// it_end = eventContainer.end();

	for (it = eventContainer.begin(); it != it_end; it++) {
		Event e = *it;
		if ((e.getStartDateTime() >= from && e.getStartDateTime() <= to) ||
		    (e.getEndDateTime() >= from && e.getEndDateTime() <= to) ||
		    (e.getStartDateTime() <= from && e.getEndDateTime() >= to)) {
			results.push_back(e);
		}
	}

	return results;
}

/**
 * Søker etter event spesifisert av eventer i q-variabelen
 */
std::vector<Event> EventHandler::findEvents(const EventHandler::QueryArgs& q) const {
	std::vector<Event> results;
	EventHandler::const_iterator it, it_end;

	bool datesDefined = (q.from.isValid() && q.to.isValid());
	bool titleDefined = !q.title.isEmpty();
	bool descriptionDefined = !q.description.isEmpty();
	bool participantDefined = !q.participant.isEmpty();
	bool eventTypeDefined = !q.eventType.isEmpty();
	bool locationDefined = !q.location.isEmpty();

	if (datesDefined) {
		Event toEvent;
		toEvent.setStartDateTime(q.to);

                // Sett en øvre grense på datoene
		it_end = eventContainer.upper_bound(toEvent);
	} else {
		it_end = eventContainer.end();
	}

	for (it = eventContainer.begin(); it != it_end; it++) {
		bool lastQuerySuccess = true;
		Event e = *it;


		if (lastQuerySuccess && datesDefined) {
			lastQuerySuccess = false;
			if ((e.getStartDateTime() >= q.from && e.getStartDateTime() <= q.to) ||
			    (e.getEndDateTime() >= q.from && e.getEndDateTime() <= q.to) ||
			    (e.getStartDateTime() <= q.from && e.getEndDateTime() >= q.to)) {
				lastQuerySuccess = true;
			}
		}

		if (lastQuerySuccess && titleDefined) {
			lastQuerySuccess = e.getTitle().contains(q.title, Qt::CaseInsensitive);
		}

		if (lastQuerySuccess && descriptionDefined) {
			lastQuerySuccess = e.getDescription().contains(q.description, Qt::CaseInsensitive);
		}

		if (lastQuerySuccess && participantDefined) {
			lastQuerySuccess = false;
			std::vector<QString> parts = e.getParticipants();

			for (unsigned int i = 0; !lastQuerySuccess && i < parts.size(); i++) {
				lastQuerySuccess = parts[i].contains(q.participant, Qt::CaseInsensitive);
			}
		}

		if (lastQuerySuccess && locationDefined) {
			lastQuerySuccess = e.getLocation().contains(q.location, Qt::CaseInsensitive);
		}

		if (lastQuerySuccess && eventTypeDefined) {
			lastQuerySuccess = e.getLocation().contains(q.eventType, Qt::CaseInsensitive);
		}

		if (lastQuerySuccess) {
			results.push_back(e);
		}
	}

	return results;
}

bool EventHandler::eventsExists(const QDateTime& from, const QDateTime& to) const {
    return findEvents(from, to).size() > 0;
}

bool EventHandler::eventsExists(const QDate& fromDate) const {
    QDateTime from = QDateTime(fromDate);
    QDateTime to = from.addDays(1);
    return eventsExists(from, to);
}

bool EventHandler::replace(const Event& oldEvent, const Event& newEvent) {
	bool success = false;

	success = removeEvent(oldEvent);
	if (success) {
		addEvent(newEvent);
	}

	return success;
}

std::vector<Event> EventHandler::getAll() const {
	return std::vector<Event>(eventContainer.begin(), eventContainer.end());
}

void EventHandler::addEvent(const Event& event) {
	if (event.getRepeats() > 0) {
		int repeats = event.getRepeats();
		Event e = event;
		e.setRepeats(0); // Sett eventet slik at repeats ikke blir husket på

		eventContainer.insert(e);

		QDateTime start = event.getStartDateTime();
		QDateTime end = event.getEndDateTime();

		for (int rep = 0; rep < repeats; rep++) {
			start = start.addDays(7);
			end = end.addDays(7);

			e.setEndDateTime(end);
			e.setStartDateTime(start);
			eventContainer.insert(e);
		}
	} else {
		eventContainer.insert(event);
	}
}

bool EventHandler::removeEvent(const Event& event) {
	std::set<Event>::iterator it = eventContainer.find(event);

	bool found = (it != eventContainer.end());

	if (found) {
		eventContainer.erase(it);
	}

	return found;
}

unsigned int EventHandler::count() const {
	return eventContainer.size();
}

EventHandler::const_iterator EventHandler::begin() const {
	return eventContainer.begin();
}

EventHandler::const_iterator EventHandler::end() const {
	return eventContainer.end();
}

void EventHandler::save() {
	QString filePath = QDir::currentPath();
	filePath += QString("/events.xml");

	qDebug() << filePath;

	FileHandler fh(filePath);
	fh.save(eventContainer);
}

void EventHandler::load() {
	QString filePath = QDir::currentPath();
	filePath += QString("/events.xml");

	qDebug() << filePath;

	eventContainer.clear();

	FileHandler fh(filePath);
	fh.load(eventContainer);
}
