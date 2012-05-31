#ifndef GAMEOBJECT_HPP_INCLUDED
#define GAMEOBJECT_HPP_INCLUDED

#include <irrlicht/irrTypes.h>
#include "viking/RTTIBase.hpp"
#include "viking/Serializable.hpp"

namespace vik
{

/*
Base class for all GameObjects in the game.
GameObjects have a state that is updated as a function of time with update()
GameObjects have custom RTTI implemented. (Inherited from RTTIBase)
GameObjects are possible to serialize/deserialize. (Inherited from Serializable)

On inheritance: Try to only subclass this class once. Twice is the absolute maximum, and multiple inheritance of this class is not allowed.
On creation: Instances of GameObjects should be created with a GameObjectFactory.
Factories should be constructed with all parameters necessary to provide necessary attributes to GameObjects.
*/
class GameObject : public Serializable, public RTTIBase
{
public:
	virtual ~GameObject(){}
	// update state as a function of delta time
	virtual void update(irr::f32 dt) = 0;
};

} // end namespace vik

#endif // GAMEOBJECT_HPP_INCLUDED
