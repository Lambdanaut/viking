#include "viking/Actor.hpp"

using namespace irr;

namespace vik
{

void Actor::setPosition(const core::vector3df& pos)
{
	sprite.setPosition(pos);
}

core::vector3df Actor::getPosition() const
{
	return sprite.getPosition();
}

} // end namespace vik
