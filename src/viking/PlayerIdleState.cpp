#include "viking/PlayerIdleState.hpp"
#include "viking/GameApp.hpp"

namespace vik
{

PlayerIdleState::PlayerIdleState(HashedString stateName, Actor* context):
ActorState(stateName, context)
{
}

void PlayerIdleState::onEnter()
{
	//GameApp::getLogger()->log("void PlayerIdleState::onEnter()");
}

void PlayerIdleState::onUpdate(irr::f32 dt)
{
	//GameApp::getLogger()->log("void PlayerIdleState::onUpdate()");
}

void PlayerIdleState::onLeave()
{
	//GameApp::getLogger()->log("void PlayerIdleState::onLeave()");
}

} // end namespace vik
