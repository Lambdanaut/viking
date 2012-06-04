#ifndef ANIMATEDSPRITE_HPP_INCLUDED
#define ANIMATEDSPRITE_HPP_INCLUDED

#include <irrlicht/irrlicht.h>

namespace vik
{

// TODO: Make this class a lot better, maybe throw it out and start a better one.
// For now just displays a black square as a billboard scene node...
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
