#include "viking/Actor.hpp"
#include <cassert>

namespace vik
{

Actor::Actor():
currentState(0)
{
}

Actor::~Actor()
{
	if (currentState)
	{
		currentState->onLeave();
	}

	for (unsigned i = 0; i < states.size(); ++i)
	{
		delete states[i];
	}
}

void Actor::startStateMachine(HashedString initialStateName)
{
	unsigned i;
	for (i = 0; i < states.size(); ++i)
	{
		if (states[i]->getName() == initialStateName)
		{
			currentState = states[i];
			break;
		}
	}
	assert(i != states.size());

	currentState->onEnter();
}

void Actor::addState(ActorState* state)
{
	states.push_back(state);
}

void Actor::switchToState(HashedString nextState)
{
	currentState->onLeave();

	std::vector<ActorState*>::iterator it;
	unsigned i;
	for (i = 0; i < states.size(); ++i)
	{
		if (states[i]->getName() == nextState)
		{
			currentState = states[i];
			break;
		}
	}
	assert(i != states.size());

	currentState->onEnter();
}

void Actor::update(irr::f32 dt)
{
	currentState->onUpdate(dt);
}

bool Actor::onEvent(const Event& e)
{
	return currentState->onEvent(e);
}

HashedString Actor::getTypeInfo() const
{
	return hashString("Actor");
}

} // end namespace vik
