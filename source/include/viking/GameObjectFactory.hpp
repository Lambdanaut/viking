#ifndef GAMEOBJECTFACTORY_HPP_INCLUDED
#define GAMEOBJECTFACTORY_HPP_INCLUDED

#include "viking/HashedString.hpp"
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
	GameObjectFactory(HashedString factoryID);
	virtual ~GameObjectFactory(){}

	// allocate and construct new instance of a GameObject subclass
	virtual GameObject* create() = 0;

	HashedString getFactoryID() const; 
private:
	HashedString factoryID;
};

} // end namespace vik

#endif // GAMEOBJECTFACTORY_HPP_INCLUDED
