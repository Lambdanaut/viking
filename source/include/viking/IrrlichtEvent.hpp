#ifndef IRRLICHTEVENT_HPP_INCLUDED
#define IRRLICHTEVENT_HPP_INCLUDED

#include <irrlicht/IEventReceiver.h>
#include "viking/Event.hpp"

namespace vik
{

// Adapter class to wrap Irrlicht's events with viking's events.
class IrrlichtEvent : public Event
{
public:
	IrrlichtEvent(const irr::SEvent& e);

	// returns reference to original irrlicht event
	const irr::SEvent& getEvent() const;

	HashedString getType() const;
private:
	const irr::SEvent& ievent;
};

} // end namespace vik

#endif // IRRLICHTEVENT_HPP_INCLUDED
