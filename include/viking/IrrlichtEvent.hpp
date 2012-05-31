#ifndef IRRLICHTEVENT_HPP_INCLUDED
#define IRRLICHTEVENT_HPP_INCLUDED

#include <irrlicht/IEventReceiver.h>
#include "viking/Event.hpp"

namespace vik
{

class IrrlichtEvent : public Event
{
public:
	IrrlichtEvent(const irr::SEvent& e);

	const irr::SEvent& getEvent() const
	{
		return ievent;
	}

	HashedString getTypeInfo() const
	{
		return hashString("IrrlichtEvent");
	}
private:
	const irr::SEvent& ievent;
};

} // end namespace vik

#endif // IRRLICHTEVENT_HPP_INCLUDED
