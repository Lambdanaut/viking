#include "viking/AnimatedSprite.hpp"
#include "viking/GameApp.hpp"

using namespace irr;

namespace vik
{

AnimatedSprite::AnimatedSprite()
{
	node = GameApp::getSceneManager()->addBillboardSceneNode();
}

AnimatedSprite::~AnimatedSprite()
{
	node->remove();
}

void AnimatedSprite::setPosition(const core::vector3df& pos)
{
	node->setPosition(pos);
}

core::vector3df AnimatedSprite::getPosition() const
{
	reeturn node->getPosition();
}

} // end namespace vik
