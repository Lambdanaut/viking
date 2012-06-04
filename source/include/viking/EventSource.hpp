#ifndef EVENTSOURCE_HPP_INCLUDED
#define EVENTSOURCE_HPP_INCLUDED

#include <list>
#include "viking/EventListener.hpp"

namespace vik
{

class Event;

// Forwards events to a list of EventListeners
class EventSource : public EventListener
{
public:
	// Distributes Event to all listeners
	bool onEvent(const Event& event);
	// adds listener to list of subscribers. Note that it is possible to add something twice (does not use set behaviour)
	void addListener(EventListener* listener);
	// removes listener. Will assert in debug builds if the listener is not in the list.
	void removeListener(EventListener* listener);
private:
	std::list<EventListener*> listeners;
};

} // end namespace vik

#endif // EVENTSOURCE_HPP_INCLUDED
