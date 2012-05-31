#include "viking/GameApp.hpp"
#include "viking/Actor.hpp"
#include "viking/PlayerFactory.hpp"
#include <irrlicht/irrlicht.h>
#include "viking/IrrlichtEvent.hpp"

using namespace irr;

namespace vik
{

GameApp* GameApp::instance;

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
	PlayerFactory pf(HashedString("TestPlayerFactory"), &rootEventSource);
	
	GameObject* player = pf.create();

	while (getDevice()->run())
	{
		player->update(17);
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

	delete player;
}

bool GameApp::OnEvent(const irr::SEvent& event)
{
	return rootEventSource.onEvent(IrrlichtEvent(event));
}

void GameApp::initDevice()
{
	// init instance
	instance = this;

	// init device
	device = createDevice(video::EDT_OPENGL, core::dimension2du(640, 480), 32, false, false, true);

	// must set event after creating the device
	// otherwise, will crash while trying to access
	// the device's timer while creating event time stamps.
	device->setEventReceiver(this);

	getDevice()->setWindowCaption(L"Viking");

	// init camera 
	scene::ICameraSceneNode* cam = getSceneManager()->addCameraSceneNode();
	cam->setTarget(core::vector3df(0,0,0));
	cam->setPosition(core::vector3df(0,0,50));
}

} // end namespace vik
