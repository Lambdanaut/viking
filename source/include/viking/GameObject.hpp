#ifndef GAMEOBJECT_HPP_INCLUDED
#define GAMEOBJECT_HPP_INCLUDED

#include <irrlicht/irrTypes.h>
#include "viking/RTTIBase.hpp"
#include "viking/Serializable.hpp"
#include "viking/ReferenceCounted.hpp"
#include "viking/GameObjectFactoryTag.hpp"
#include "viking/GameTime.hpp"

namespace vik
{

/*
Base class for all GameObjects in the game.
GameObjects have a state that is updated as a function of time with update()
GameObjects have custom RTTI implemented. (Inherited from RTTIBase)
GameObjects are possible to serialize/deserialize. (Inherited from Serializable)
GameObjects have their allocation managed by reference counting.
TODO: Record a list of all GameObject allocations and deallocations and print some information to detect memory leaks in debug builds.

On inheritance: Try to only subclass this class once. Twice is the absolute maximum, and multiple inheritance of this class is not allowed.

On creation: Instances of GameObjects should be created with a GameObjectFactory.
Factories should be constructed with all parameters necessary to provide necessary attributes to GameObjects.
Factories are given a hook before objects are deallocated to properly destroy them.
*/
class GameObject : public Serializable, public RTTIBase, public ReferenceCounted
{
public:
	GameObject(GameObjectFactory* manufacturer);
	virtual ~GameObject(){}
	// update state as a function of delta time
	virtual void update(GameTime& time) = 0;
private:
	GameObjectFactoryTag receipt;
};

} // end namespace vik

#endif // GAMEOBJECT_HPP_INCLUDED
