#ifndef KEYMAP_HPP_INCLUDED
#define KEYMAP_HPP_INCLUDED

#include "viking/EventListener.hpp"
#include <irrlicht/Keycodes.h>
#include <bitset>

namespace vik
{

class Event;

// records state of all keys, whether they are currently up or down. Must be fed events to be kept up to date.
class KeyMap : public EventListener
{
public:
	// returns true if the event is an irrlicht key event (in which case it is handled)
	bool onEvent(const Event& e);
	// returns true if the key is currently being held down or false if it isn't
	bool isKeyDown(irr::EKEY_CODE key) const;
private:
	std::bitset<irr::KEY_KEY_CODES_COUNT> keyDownMap;
};

} // end namespace vik

#endif // KEYMAP_HPP_INCLUDED

