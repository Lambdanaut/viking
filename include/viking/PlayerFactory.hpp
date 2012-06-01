#ifndef PLAYERFACTORY_HPP_INCLUDED
#define PLAYERFACTORY_HPP_INCLUDED

#include "viking/GameObjectFactory.hpp"

namespace vik
{

class GameObject;
class GameObjectEngine;
class EventSource;

class PlayerFactory : public GameObjectFactory
{
public:
	PlayerFactory(HashedString factoryID, EventSource* playerEventSource);
	GameObject* create();
	void destroy(GameObject* destroyMe);
private:
	EventSource* playerEventSource;
};

} // end namespace vik

#endif // PLAYERFACTORY_HPP_INCLUDED
