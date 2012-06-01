#ifndef EVENTLISTENER_HPP_INCLUDED
#define EVENTLISTENER_HPP_INCLUDED

namespace vik
{

class Event;

class EventListener
{
public:
	virtual ~EventListener(){}
	// return true if event is handled
	bool onEvent(const Event& e){ return false; }
};

} // end namespace vik

#endif // EVENTLISTENER_HPP_INCLUDED
