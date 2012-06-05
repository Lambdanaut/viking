#include "viking/Controller.hpp"
#include <irrlicht/Keycodes.h>

namespace vik
{

Controller::Controller(const ControlScheme& scheme):
scheme(scheme)
{
}

void Controller::update(const KeyMap& keyMap)
{
	leftStick.X = keyMap.isKeyDown(scheme.left) ? -1.0 : 0.0;
	leftStick.X += keyMap.isKeyDown(scheme.right) ? 1.0 : 0.0;
	leftStick.Y = keyMap.isKeyDown(scheme.up) ? 1.0 : 0.0;
	leftStick.Y += keyMap.isKeyDown(scheme.down) ? -1.0 : 0.0;
	leftStick.normalize();
}

irr::core::vector2df Controller::getLeftThumbstick() const
{
	return leftStick;
}

} // end namespace vik
