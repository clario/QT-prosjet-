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

std::vector<Event> EventHandler::findEvents(const QDate& from, const QDate& to) const {
	// Denne metoden finner alle events mellom to datoer. søket er som inklusivt.
	// Det finner ALLE event som start, slutter eller pågpr innenfor et tisrom.
	std::vector<Event> results;
	EventHandler::const_iterator it, it_end;

	Event toEvent;
	toEvent.setStartDateTime(QDateTime(to));
	it_end = eventContainer.upper_bound(toEvent);
	// it_end = eventContainer.end();

	for (it = eventContainer.begin(); it != it_end; it++) {
		Event e = *it;
		if ((e.getStartDate() >= from && e.getStartDate() <= to) ||
		    (e.getEndDate() >= from && e.getEndDate() <= to) ||
		    (e.getStartDate() <= from && e.getEndDate() >= to)) {
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
