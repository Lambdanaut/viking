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

// manages a collection of objects
class GameObjectEngine
{
public:
	~GameObjectEngine();

	// updates all objects
	void update(GameTime& time);

	// adds object to set and increments reference count
	void addObject(GameObject* object);
	// removes object from set and decrements reference count
	void removeObject(GameObject* object);

	// lifetime of factories is held by GameObjectEngine. They grab and drop reference counts.
	void addFactory(GameObjectFactory* factory);
	void removeFactory(GameObjectFactory* factory);

	// find factory associated with ID and return object created by it
	// the ownership of objects created by this method belongs to only the GameObjectEngine called.
	// the objects created are automatically also added to the game object engine
	// You must also grab a reference to the created game object if you want to extend its lifetime beyond the lifetime of the game object engine
	GameObject* create(HashedString factoryID);
private:
	// resist the temptation to make this public. the public interface depends on this being private.
	void addObjectWithoutIncrRefCnt(GameObject* object);

	std::set<GameObject*> objectList;
	std::vector<GameObjectFactory*> factoryList;
};

} // end namespace vik

#endif // GAMEOBJECTENGINE_HPP_INCLUDED
