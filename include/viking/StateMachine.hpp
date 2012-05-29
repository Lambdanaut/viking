#ifndef STATEMACHINE_HPP_INCLUDED
#define STATEMACHINE_HPP_INCLUDED

#include "viking/HashString.hpp"
#include "viking/State.hpp"
#include <map>

namespace vik
{

// template parameter is the type of the context of the states
template<class T>
class StateMachine
{
public:
	// if deleteStatesOnDestroy is true, "delete" will be called on all state
	// added using addState(). Otherwise, it will not.
	StateMachine(bool deleteStatesOnDestroy);
	~StateMachine();

	// add a state to the machine which can be accessed by the given name
	void addState(HashedString stateName, State<T>* state);
	// initializes the state machine with the given state
	void start(HashedString initialStateName);
	// leave current state and enter the new one
	// causes undefined behaviour if state machine is not yet started using start()
	void switchToState(HashedString stateName);

	// sends update message to current state
	void update(irr::f32 dt);
private:
	State<T>* currentState;
	bool deleteStatesOnDestroy;
	std::map<HashedString, State<T>*> states;
};

template<class T>
StateMachine<T>::StateMachine(bool deleteStatesOnDestroy):
currentState(0),
deleteStatesOnDestroy(deleteStatesOnDestroy)
{
}

template<class T>
StateMachine<T>::~StateMachine()
{
	if (deleteStatesOnDestroy)
	{
		for (std::map<HashedString, State<T>*> it = states.begin();
			it != states.end(); ++it)
		{
			delete it->second;
		}
	}
}

template<class T>
StateMachine<T>::addState(HashedString stateName, State<T>* state)
{
	states[stateName] = state;
}

template<class T>
StateMachine<T>::start(HashedString initialStateName)
{
	switchToState(initialStateName);
}

template<class T>
StateMachine<T>::switchToState(HashedString stateName)
{
	if (currentState)
	{
		currentState->onLeave();
	}
	currentState = states[stateName];
	currentState->onEnter();
}

template<class T>
StateMachine<T>::update(irr::f32 dt)
{
	if (currentState)
	{
		currentState->onUpdate(dt);
	}
}

} // end namespace vik

#endif // STATEMACHINE_HPP_INCLUDED
