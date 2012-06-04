#ifndef EVENTLISTENER_HPP_INCLUDED
#define EVENTLISTENER_HPP_INCLUDED

namespace vik
{

class Event;

// Interface enabling class to respond to Event signals
class EventListener
{
public:
	virtual ~EventListener(){}
	// return true if event is handled
	bool onEvent(const Event& e){ return false; }
};

} // end namespace vik

#endif // EVENTLISTENER_HPP_INCLUDED
