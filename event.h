#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <contact.h>

class Event
{
public:
    Event();
private:
    std::string title;
    std::string eventType;
    std::string location;
    calendar::Contact* participants;
};

#endif // EVENT_H
