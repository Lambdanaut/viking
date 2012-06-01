#ifndef ANIMATEDSPRITE_HPP_INCLUDED
#define ANIMATEDSPRITE_HPP_INCLUDED

#include <irrlicht/irrlicht.h>

namespace vik
{

class AnimatedSprite
{
public:
	AnimatedSprite();
	~AnimatedSprite();
	void setPosition(const irr::core::vector3df& pos);
	irr::core::vector3df getPosition() const;
private:
	irr::scene::IBillboardSceneNode* node;
};

} // end namespace vik

#endif // ANIMATEDSPRITE_HPP_INCLUDED
