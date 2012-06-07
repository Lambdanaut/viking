#include "viking/AnimatedSprite.hpp"
#include "viking/GameApp.hpp"

using namespace irr;

namespace vik
{

AnimatedSprite::AnimatedSprite()
{
	video::ITexture* t = GameApp::getVideoDriver()->getTexture("../../../art/sketch1.png");
	node = GameApp::getSceneManager()->addBillboardSceneNode(0, core::dimension2df(t->getSize()));
	node->setMaterialFlag(video::EMF_LIGHTING, false);
	node->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL_REF);
	node->setMaterialTexture(0, t);
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
	return node->getPosition();
}

} // end namespace vik
