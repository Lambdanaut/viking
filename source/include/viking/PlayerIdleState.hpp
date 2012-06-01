#ifndef PLAYERIDLESTATE_HPP_INCLUDED
#define PLAYERIDLESTATE_HPP_INCLUDED

#include "viking/ActorState.hpp"

namespace vik
{

class PlayerIdleState : public ActorState
{
public:
	PlayerIdleState(HashedString stateName, Actor* context);
	void onEnter();
	void onUpdate(GameTime& time);
	void onLeave();
	bool onEvent(const Event& e);
};

} // end namespace vik

#endif // PLAYERIDLESTATE_HPP_INCLUDED
