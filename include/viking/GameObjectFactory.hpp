#ifndef GAMEOBJECTFACTORY_HPP_INCLUDED
#define GAMEOBJECTFACTORY_HPP_INCLUDED

#include "viking/HashString.hpp"
#include "viking/ReferenceCounted.hpp"

namespace vik
{

class GameObject;

// interface for defining how game objects are created
class GameObjectFactory : public ReferenceCounted
{
public:
	// factoryID is used to make calls to this factory at runtime
	// Each factory in a GameObjectEngine should have a unique ID
	inline GameObjectFactory(HashedString factoryID);
	virtual ~GameObjectFactory(){}

	// allocate and construct new instance of a GameObject subclass
	virtual GameObject* create() = 0;

	// unwrap everything from the game object, destroy it but don't deallocate it
	virtual void destroy(GameObject* destroyMe) = 0;

	inline HashedString getFactoryID() const; 
private:
	HashedString factoryID;
};

GameObjectFactory::GameObjectFactory(HashedString factoryID):
factoryID(factoryID)
{
}

HashedString GameObjectFactory::getFactoryID() const
{
	return factoryID;
}

} // end namespace vik

#endif // GAMEOBJECTFACTORY_HPP_INCLUDED
