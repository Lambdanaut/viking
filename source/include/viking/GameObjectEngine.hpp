#ifndef GAMEOBJECTENGINE_HPP_INCLUDED
#define GAMEOBJECTENGINE_HPP_INCLUDED

#include <set>
#include <vector>
#include "viking/GameTime.hpp"
#include "viking/GameObject.hpp"
#include "viking/GameObjectFactory.hpp"

namespace vik
{

class GameObject;
class GameTime;

// manages a collection of objects and encapsulates their creation using factories
class GameObjectEngine
{
public:
	// drops 
	~GameObjectEngine();

	// updates all objects
	void update(GameTime& time);

	// adds object to set and increments reference count
	// in other words, the object engine shares ownership of the objects added to it.
	// the list of objects is implemented as a set. Therefore, each object can only exist in the object engine once at a time. 
	// asserts in debug builds if an item is added twice
	void addObject(GameObject* object);
	// removes object from set and decrements reference count
	// in debug builds, asserts if object is not found.
	void removeObject(GameObject* object);

	// lifetime of factories is held by GameObjectEngine.
	// They grab and drop reference counts.
	// In other words, ownership of factories added is shared with the object engine.
	// factories are stored as a set, therefore only one instance of each factory can be added at once.
	// will assert in debug builds if the factory is there/not there when it shouldn't/should
	void addFactory(GameObjectFactory* factory);
	void removeFactory(GameObjectFactory* factory);

	// find factory associated with ID and return object created by it
	// the ownership of objects created by this method belongs to only the GameObjectEngine called.
	// the objects created are automatically also added to the game object engine
	// You must also grab a reference to the created game object if you want to extend its lifetime beyond the lifetime of the game object engine
	// will assert in debug mode if the factory is not found (TODO: Should it not?), and will return NULL in that case in both debug and release.
	GameObject* create(HashedString factoryID);
private:
	// resist the temptation to make this public. the public interface depends on this being private.
	void addObjectWithoutIncrRefCnt(GameObject* object);

	std::set<GameObject*> objectList;
	std::set<GameObjectFactory*> factoryList;
};

} // end namespace vik

#endif // GAMEOBJECTENGINE_HPP_INCLUDED
