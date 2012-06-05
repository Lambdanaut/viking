#include "viking/KeyMap.hpp"
#include "viking/IrrlichtEvent.hpp"

namespace vik
{

bool KeyMap::onEvent(const Event& e)
{
	if (e.getType() == HashedString("IrrlichtEvent"))
	{
		const IrrlichtEvent& ie = static_cast<const IrrlichtEvent&>(e);

		const irr::SEvent& se = ie.getEvent();

		if (se.EventType == irr::EET_KEY_INPUT_EVENT)
		{
			keyDownMap[se.KeyInput.Key] = se.KeyInput.PressedDown;
			return true;
		}
	}

	return false;
}

bool KeyMap::isKeyDown(irr::EKEY_CODE key) const
{
	return keyDownMap[key];
}

} // end namespace vik
