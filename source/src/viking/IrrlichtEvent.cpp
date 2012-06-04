#include "viking/IrrlichtEvent.hpp"

namespace vik
{

IrrlichtEvent::IrrlichtEvent(const irr::SEvent& e):
ievent(e)
{
}

const irr::SEvent& IrrlichtEvent::getEvent() const
{
	return ievent;
}

HashedString IrrlichtEvent::getType() const
{
	return HashedString("IrrlichtEvent");
}

} // end namespace vik
