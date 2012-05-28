#ifndef ACTOR_HPP_INCLUDED
#define ACTOR_HPP_INCLUDED

#include <irrlicht/irrlicht.h>
#include "viking/AnimatedSprite.hpp"

namespace vik
{

class Actor
{
public:
	void setPosition(const irr::core::vector3df& pos);
	irr::core::vector3df getPosition() const;
private:
	AnimatedSprite sprite;
};

} // end namespace vik

#endif // ACTOR_HPP_INCLUDED
