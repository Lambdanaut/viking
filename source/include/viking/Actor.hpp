#ifndef ACTOR_HPP_INCLUDED
#define ACTOR_HPP_INCLUDED

#include "viking/GameObject.hpp"
#include "viking/ActorState.hpp"
#include "viking/AnimatedSprite.hpp"
#include <vector>

namespace vik
{

class ActorFactory;

class Actor : public GameObject, public EventListener
{
public:
	// Takes reference to manufacturer in order to give the manufacturer a hook while deleting
	Actor(ActorFactory* manufacturer);
	~Actor();
	
	// sets the current state to the given state and enters it
	void startStateMachine(HashedString initialStateName);
	// Adds a state to the list of possible states.
	void addState(ActorState* state);
	// leaves the current state and enters the next state
	void switchToState(HashedString nextState);

	// updates the current state
	void update(GameTime& time);

	// Passes on events to the current state
	bool onEvent(const Event& e);
private:
	ActorFactory* manufacturer;

	ActorState* currentState;
	std::vector<ActorState*> states;

	AnimatedSprite sprite;
};

} // end namespace vik

#endif // ACTOR_HPP_INCLUDED
