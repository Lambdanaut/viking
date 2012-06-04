#ifndef PLAYERFACTORY_HPP_INCLUDED
#define PLAYERFACTORY_HPP_INCLUDED

#include "viking/ActorFactory.hpp"

namespace vik
{

class EventSource;

// Creates actor decorated to be players
class PlayerFactory : public ActorFactory
{
public:
	PlayerFactory(HashedString factoryID, EventSource* playerEventSource);
	GameObject* create();
	void destroy(Actor* destroyMe);
private:
	EventSource* playerEventSource;
};

} // end namespace vik

#endif // PLAYERFACTORY_HPP_INCLUDED
