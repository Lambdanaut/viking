#ifndef PLAYERFACTORY_HPP_INCLUDED
#define PLAYERFACTORY_HPP_INCLUDED

#include "viking/GameObjectFactory.hpp"

namespace vik
{

class GameObject;
class EventSource;

class PlayerFactory : public GameObjectFactory
{
public:
	PlayerFactory(HashedString factoryID, EventSource* playerEventSource);
	GameObject* create();
private:
	EventSource* playerEventSource;
};

} // end namespace vik

#endif // PLAYERFACTORY_HPP_INCLUDED
