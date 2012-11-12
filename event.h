/*
  * Obligatorisk innlevering i Qt
  * Klasseansvarlig: Endre
  */

#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <contact.h>

using namespace std;

class Event
{
public:
    Event();
private:
    string title;
    string eventType;
    string location;
    calendar::Contact* participants;
};

#endif // EVENT_H
