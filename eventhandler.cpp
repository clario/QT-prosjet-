/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#include "eventhandler.h"

using namespace calendar;

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

std::vector<Event> EventHandler::getAll() const {
	return std::vector<Event>(eventContainer.begin(), eventContainer.end());
};

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
