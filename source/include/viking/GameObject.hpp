#ifndef GAMEOBJECT_HPP_INCLUDED
#define GAMEOBJECT_HPP_INCLUDED

#include "viking/Serializable.hpp"
#include "viking/ReferenceCounted.hpp"
#include "viking/GameTime.hpp"

namespace vik
{

// Base class for all GameObjects in the game.
// GameObjects have a state that is updated as a function of time with update()
// GameObjects are possible to serialize/deserialize. (Inherited from Serializable)
// GameObjects have their allocation managed by reference counting.
// TODO: Record a list of all GameObject allocations and deallocations and print some information to detect memory leaks in debug builds.
// TODO: Either that, or overload the global new operator (though I find this technique to be an anti-pattern for many reasons)
// On inheritance: Try to only subclass this class once. Twice is the absolute maximum, and multiple inheritance of this class is not allowed.
class GameObject : public Serializable, public ReferenceCounted
{
public:
	virtual ~GameObject(){}
	// update state as a function of delta time
	virtual void update(GameTime& time) = 0;
};

} // end namespace vik

#endif // GAMEOBJECT_HPP_INCLUDED
