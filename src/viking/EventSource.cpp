#include "viking/EventSource.hpp"
#include "viking/Event.hpp"
#include <algorithm>
#include <cassert>

namespace vik
{

bool EventSource::onEvent(const Event& event)
{
	bool handled = false;
	for (std::list<EventListener*>::iterator it = listeners.begin(); it != listeners.end() && !handled; ++it)
	{
		handled = (*it)->onEvent(event);
	}
	return handled;
}

void EventSource::addListener(EventListener* listener)
{
	listeners.push_back(listener);
}

void EventSource::removeListener(EventListener* listener)
{
	std::list<EventListener*>::iterator it;
	it = std::find(listeners.begin(), listeners.end(), listener);
	assert(it != listeners.end());
	listeners.erase(it);
}

} // end namespace vik
