#include "viking/ControllerControlPanel.hpp"

namespace vik
{

ControllerControlPanel::~ControllerControlPanel()
{
	for (int i = static_cast<int>(controllers.size()) - 1; i >= 0; --i)
	{
		delete controllers[i];
		controllers[i] = 0;
	}
}

void ControllerControlPanel::update(const KeyMap& keyMap)
{
	for (int i = static_cast<int>(controllers.size()) - 1; i >= 0; --i)
	{
		controllers[i]->update(keyMap);
	}
}

Controller* ControllerControlPanel::addController(const ControlScheme& scheme)
{
	controllers.push_back(new Controller(scheme));
	return controllers.back();
}

unsigned ControllerControlPanel::getPlayerNumberFromController(Controller* controller) const
{
	for (int i = static_cast<int>(controllers.size()) - 1; i >= 0; --i)
	{
		if (controllers[i] == controller)
		{
			return i+1;
		}
	}

	return 0;
}

Controller* ControllerControlPanel::getControllerByPlayer(unsigned playerNumber) const
{
	if (playerNumber > controllers.size() || playerNumber == 0)
	{
		return 0;
	}
	return controllers[playerNumber-1];
}

} // end namespace vik
