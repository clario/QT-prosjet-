/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#include <QDebug>
#include <QDir>

#include "eventhandler.h"
#include "filewriter.h"

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

std::vector<Event> EventHandler::findEvents(const EventHandler::QueryArgs& q) const {
	std::vector<Event> results;
	EventHandler::const_iterator it, it_end;

	bool datesDefined = (q.from.isValid() && q.to.isValid());
	bool titleDefined = !q.title.isEmpty();
	bool participantDefined = !q.participant.isEmpty();
	bool eventTypeDefined = !q.eventType.isEmpty();
	bool locationDefined = !q.location.isEmpty();

	if (datesDefined) {
		Event toEvent;
		toEvent.setStartDateTime(q.to);
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
	eventContainer.insert(event);
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

	FileWriter fw(filePath);
	fw.save(eventContainer);
}

void EventHandler::load() {
	QString filePath = QDir::currentPath();
	filePath += QString("/events.xml");

	qDebug() << filePath;

	//FileLoader fl(filePath);
	//fl.save(eventContainer);
}
