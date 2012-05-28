#include "viking/GameApp.hpp"
#include "viking/Actor.hpp"
#include <irrlicht/irrlicht.h>

using namespace irr;

namespace vik
{

GameApp* GameApp::singleton;

GameApp::GameApp()
{
	initDevice();

	const wchar_t* header = L"Viking prototype iteration 1";
	getGUIEnvironment()->addStaticText(header, core::recti(0,0,100,100));
}

GameApp::~GameApp()
{
	device->drop();
}

void GameApp::main()
{
	Actor test_actor;

	while (getDevice()->run())
	{
		if (getDevice()->isWindowActive())
		{
			getVideoDriver()->beginScene(true, true, video::SColor(255,100,149,237));

			getSceneManager()->drawAll();
			getGUIEnvironment()->drawAll();

			getVideoDriver()->endScene();
		}
		else
		{
			getDevice()->yield();
		}
	}
}

bool GameApp::OnEvent(const irr::SEvent& event)
{
	return false;
}

void GameApp::initDevice()
{
	// init singleton
	singleton = this;

	// init device
	device = createDevice(video::EDT_OPENGL, core::dimension2du(640, 480), 32, false, false, true, this);
	getDevice()->setWindowCaption(L"Viking");

	// init camera 
	scene::ICameraSceneNode* cam = getSceneManager()->addCameraSceneNode();
	cam->setTarget(core::vector3df(0,0,0));
	cam->setPosition(core::vector3df(0,0,50));
}

} // end namespace vik
