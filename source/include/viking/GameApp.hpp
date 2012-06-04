#ifndef GAMEAPP_HPP_INCLUDED
#define GAMEAPP_HPP_INCLUDED
#include <irrlicht/irrlicht.h>
#include "viking/EventSource.hpp"
#include "viking/GameObjectEngine.hpp"
#include "viking/GameTime.hpp"

namespace vik
{

// Class to wrap the global context of the application.
// The true main() function belongs to this class, and it is the one that distributes irrlicht events to all other event listeners in the game.
// Although it has singleton-like functions, it is not actually a singleton. It cannot be refered to in a static context, only once the real main has started.
class GameApp : public irr::IEventReceiver
{
public:
	GameApp();
	~GameApp();

	// main loop of game
	void main();
	// distributes irrlicht callback for events
	bool OnEvent(const irr::SEvent& event);

	// returns last created instance of GameApp. All the following getters just forward calls to the IrrlichtDevice belonging to this instance.
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
