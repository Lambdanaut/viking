#ifndef CONTROLSCHEME_HPP_INCLUDED
#define CONTROLSCHEME_HPP_INCLUDED

#include "viking/Serializable.hpp"

namespace vik
{

// The control scheme to define for a single player
// TODO: Allow serializing/deserializing this
struct ControlScheme : public Serializable
{
	ControlScheme():
	up(irr::KEY_KEY_W),
	down(irr::KEY_KEY_S),
	left(irr::KEY_KEY_A),
	right(irr::KEY_KEY_D)
	{
	}

	irr::EKEY_CODE up;
	irr::EKEY_CODE down;
	irr::EKEY_CODE left;
	irr::EKEY_CODE right;
};

} // end namespace vik

#endif // CONTROLSCHEME_HPP_INCLUDED
