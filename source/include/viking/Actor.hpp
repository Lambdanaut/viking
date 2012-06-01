#ifndef ACTOR_HPP_INCLUDED
#define ACTOR_HPP_INCLUDED

#include "viking/GameObject.hpp"
#include "viking/ActorState.hpp"
#include <vector>

namespace vik
{

class GameObjectFactory;

class Actor : public GameObject, public EventListener
{
public:
	Actor(GameObjectFactory* manufacturer);
	~Actor();
	
	// sets the current state to the given state and enters it
	void startStateMachine(HashedString initialStateName);
	// Adds a state to the list of possible states.
	void addState(ActorState* state);
	// leaves the current state and enters the next state
	void switchToState(HashedString nextState);

	// updates the current state
	void update(GameTime& time);

	bool onEvent(const Event& e);

	HashedString getTypeInfo() const;
private:
	ActorState* currentState;
	std::vector<ActorState*> states;
};

} // end namespace vik

#endif // ACTOR_HPP_INCLUDED
