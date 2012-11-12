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
	std::vector<Event> results;
	std::vector<Event>::const_iterator it;

	for (it = eventContainer.begin(); it != eventContainer.end(); it++) {
		Event e = *it;
		if (e.getStartDate() >= from && e.getStartDate() <= to) {
			results.push_back(e);
		}
	}

	return results;
}

std::vector<Event> EventHandler::getAll() const {
	return eventContainer;
};

void EventHandler::addEvent(const Event& event) {
	eventContainer.push_back(event);
}

Event EventHandler::removeEvent(const Event& event) {
	std::vector<Event>::const_iterator it;

	bool found = false;

	for (it = eventContainer.begin(); it != eventContainer.end(); it++) {
		Event e = *it;
		if (event == e) {
			found = true;
		}
	}

	if (found) {
		return event;
	}

	return Event();
}
