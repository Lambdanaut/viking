#ifndef CONTROLLERCONTROLPANEL_HPP_INCLUDED
#define CONTROLLERCONTROLPANEL_HPP_INCLUDED

#include "viking/Controller.hpp"
#include <vector>

namespace vik
{

// Manages the set of controllers acting on the game
// This class is a metaphor for the front panel of an arcade cabinet: http://en.wikipedia.org/wiki/Video_game_arcade_cabinet#Parts_of_an_arcade_cabinet
class ControllerControlPanel
{
public:
	~ControllerControlPanel();
	// updates state of controllers
	void update(const KeyMap& keyMap);
	// add a controller to the end of the list and return it
	// ControlPanel has sole ownership of the Controller
	Controller* addController(const ControlScheme& scheme);
	// gets player number (which is 1 indexed) from a controller
	// if it's not found, returns 0
	unsigned getPlayerNumberFromController(Controller* controller) const;
	// player number is 1 indexed, as in most games.
	// returns null if the player doesn't exist
	Controller* getControllerByPlayer(unsigned playerNumber) const;
private:
	std::vector<Controller*> controllers;
};

} // end namespace vik

#endif // CONTROLLERCONTROLPANEL_HPP_INCLUDED
