#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#include <irrlicht/irrTypes.h>
#include "viking/RTTIBase.hpp"

namespace vik
{

// meant to be passed around by EventListeners and EventSources.
// Typeinfo is used to downcast to proper derived event type
class Event : public RTTIBase
{
public:
	Event();
	// return creation time of event 
	irr::u32 getTimeStamp() const;
	HashedString getTypeInfo() const
	{
		return HashedString("Event");
	}
private:
	irr::u32 timeStamp;
};

} // end namespace vik

#endif // EVENT_HPP_INCLUDED
