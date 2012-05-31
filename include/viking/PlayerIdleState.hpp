#ifndef PLAYERIDLESTATE_HPP_INCLUDED
#define PLAYERIDLESTATE_HPP_INCLUDED

#include "viking/ActorState.hpp"
#include <irrlicht/IEventReceiver.h>

namespace vik
{

class PlayerIdleState : public ActorState
{
public:
	PlayerIdleState(HashedString stateName, Actor* context);
	void onEnter();
	void onUpdate(irr::f32 dt);
	void onLeave();
};

} // end namespace vik

#endif // PLAYERIDLESTATE_HPP_INCLUDED
