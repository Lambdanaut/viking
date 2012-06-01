#include "viking/GameObjectEngine.hpp"
#include "viking/GameApp.hpp"
#include <cassert>
#include <algorithm>

namespace vik
{

GameObjectEngine::~GameObjectEngine()
{
	for (std::set<GameObject*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
	{
		(*it)->dropReference();
	}
}

void GameObjectEngine::update(GameTime& time)
{
	for (std::set<GameObject*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
	{
		(*it)->update(time);
	}
}

void GameObjectEngine::addObject(GameObject* object)
{
	assert(objectList.find(object) == objectList.end());
	object->grabReference();
	objectList.insert(object);
}

void GameObjectEngine::removeObject(GameObject* object)
{
	object->dropReference();
	objectList.erase(objectList.find(object));
}

void GameObjectEngine::addFactory(GameObjectFactory* factory)
{
	factory->grabReference();
	factoryList.push_back(factory);
}

void GameObjectEngine::removeFactory(GameObjectFactory* factory)
{
	std::vector<GameObjectFactory*>::iterator it;
	it = std::find(factoryList.begin(),factoryList.end(), factory);
	assert(it != factoryList.end());
	factory->dropReference();
	factoryList.erase(it);
}

GameObject* GameObjectEngine::create(HashedString factoryID)
{
	for (std::vector<GameObjectFactory*>::iterator it = factoryList.begin(); it != factoryList.end(); ++it)
	{
		if ((*it)->getFactoryID() == factoryID)
		{
			GameObject* newObject = (*it)->create();
			// don't need to increment reference count because it was set to 1 when the factory call was made
			addObjectWithoutIncrRefCnt(newObject);
			return newObject;
		}
	}
	assert(false);
	return 0;
}

void GameObjectEngine::addObjectWithoutIncrRefCnt(GameObject* object)
{
	assert(objectList.find(object) == objectList.end());
	objectList.insert(object);
}

} // end namespace vik
