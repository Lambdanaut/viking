#ifndef GAMEOBJECTFACTORY_HPP_INCLUDED
#define GAMEOBJECTFACTORY_HPP_INCLUDED

#include "viking/HashString.hpp"

namespace vik
{

class GameObject;

// interface for defining how game objects are created
class GameObjectFactory
{
public:
	// factoryID is used to make calls to this factory at runtime
	// Each factory in a GameObjectEngine should have a unique ID
	inline GameObjectFactory(HashedString factoryID);
	virtual ~GameObjectFactory(){}

	// construct new instance of a GameObject subclass
	virtual GameObject* create() = 0;

	HashedString getFactoryID() const { return factoryID; }
private:
	HashedString factoryID;
};

GameObjectFactory::GameObjectFactory(HashedString factoryID):
factoryID(factoryID)
{
}

} // end namespace vik

#endif // GAMEOBJECTFACTORY_HPP_INCLUDED
