#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#include <irrlicht/irrTypes.h>
#include "viking/HashedString.hpp"

namespace vik
{

// meant to be passed around by EventListeners and EventSources.
// Some type information is used to downcast to proper derived event type
class Event
{
public:
	Event();
	// return creation time of event 
	irr::u32 getTimeStamp() const;
	// return type name of event as a hashed string
	inline HashedString getType() const;
private:
	irr::u32 timeStamp;
};

HashedString Event::getType() const
{
	return HashedString("Event");
}

} // end namespace vik

#endif // EVENT_HPP_INCLUDED
