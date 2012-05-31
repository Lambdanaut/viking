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
	Actor* player = new Actor();

	PlayerIdleState* idleState = new PlayerIdleState(hashString("Idle"), player);
	player->addState(idleState);

	player->startStateMachine(hashString("Idle"));

	return player;
}

}
