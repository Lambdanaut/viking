#ifndef GAMEAPP_HPP_INCLUDED
#define GAMEAPP_HPP_INCLUDED
#include <irrlicht/irrlicht.h>
#include "viking/EventSource.hpp"
#include "viking/GameObjectEngine.hpp"
#include "viking/GameTime.hpp"

namespace vik
{

class GameApp : public irr::IEventReceiver
{
public:
	GameApp();
	~GameApp();

	void main();
	bool OnEvent(const irr::SEvent& event);

	static inline GameApp* getInstance();
	static inline irr::IrrlichtDevice* getDevice();
	static inline irr::video::IVideoDriver* getVideoDriver();
	static inline irr::scene::ISceneManager* getSceneManager();
	static inline irr::gui::IGUIEnvironment* getGUIEnvironment();
	static inline irr::ILogger* getLogger();
	static inline irr::ITimer* getTimer();

private:
	static GameApp* instance;
	irr::IrrlichtDevice* device;

	void initDevice();

	EventSource rootEventSource;
	GameTime* rootTime;
};

GameApp* GameApp::getInstance()
{
	return instance;
}

irr::IrrlichtDevice* GameApp::getDevice()
{
	return getInstance()->device;
}

irr::video::IVideoDriver* GameApp::getVideoDriver()
{
	return getDevice()->getVideoDriver();
}

irr::scene::ISceneManager* GameApp::getSceneManager()
{
	return getDevice()->getSceneManager();
}

irr::gui::IGUIEnvironment* GameApp::getGUIEnvironment()
{
	return getDevice()->getGUIEnvironment();
}

irr::ILogger* GameApp::getLogger()
{
	return getDevice()->getLogger();
}

irr::ITimer* GameApp::getTimer()
{
	return getDevice()->getTimer();
}

} // end namespace vik

#endif // GAMEAPP_HPP_INCLUDED
