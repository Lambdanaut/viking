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
	bool onEvent(const Event& event);
	void addListener(EventListener* listener);
	void removeListener(EventListener* listener);
private:
	std::list<EventListener*> listeners;
};

} // end namespace vik

#endif // EVENTSOURCE_HPP_INCLUDED
