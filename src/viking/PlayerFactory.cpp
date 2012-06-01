#include "viking/PlayerFactory.hpp"
#include "viking/Actor.hpp"
#include "viking/EventSource.hpp"

#include "viking/PlayerIdleState.hpp"

namespace vik
{

PlayerFactory::PlayerFactory(HashedString factoryID, EventSource* playerEventSource):
GameObjectFactory(factoryID),
playerEventSource(playerEventSource)
{
}

GameObject* PlayerFactory::create()
{
	Actor* player = new Actor(this);

	playerEventSource->addListener(player);

	PlayerIdleState* idleState = new PlayerIdleState(HashedString("Idle"), player);
	player->addState(idleState);

	player->startStateMachine(HashedString("Idle"));

	return player;
}

void PlayerFactory::destroy(GameObject* destroyMe)
{
	Actor* player = static_cast<Actor*>(destroyMe);

	playerEventSource->removeListener(player);
}

}
