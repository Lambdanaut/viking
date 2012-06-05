#ifndef CONTROLLER_HPP_INCLUDED
#define CONTROLLER_HPP_INCLUDED

#include "viking/EventListener.hpp"
#include <irrlicht/Keycodes.h>
#include <irrlicht/vector2d.h>
#include "viking/KeyMap.hpp"
#include "viking/ControlScheme.hpp"

namespace vik
{

// maps regular input to a virtual controller
// simulates thumbstick from discrete direction arrows
class Controller
{
public:
	// create a virtual controller mapped to the given control scheme
	Controller(const ControlScheme& scheme);
	// updates the state of the thumbstick as a function of the keymap
	void update(const KeyMap& keyMap);
	// returns the normalized direction vector in which the left thumbstick is oriented. With a keyboard (or other discrete directional input), arrow keys simulate a thumbstick.
	irr::core::vector2df getLeftThumbstick() const;
private:
	irr::core::vector2df leftStick;

	ControlScheme scheme;
};

} // end namespace vik

#endif // CONTROLLER_HPP_INCLUDED
