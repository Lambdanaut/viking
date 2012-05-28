#ifndef GAMEAPP_HPP_INCLUDED
#define GAMEAPP_HPP_INCLUDED
#include <irrlicht/irrlicht.h>

namespace vik
{

class GameApp : public irr::IEventReceiver
{
public:
	GameApp();
	~GameApp();


	void main();
	bool OnEvent(const irr::SEvent& event);

	static GameApp* getInstance()
	{
		return singleton;
	}
	static irr::IrrlichtDevice* getDevice()
	{
		return getInstance()->device;
	}
	static irr::video::IVideoDriver* getVideoDriver()
	{
		return getDevice()->getVideoDriver();
	}
	static irr::scene::ISceneManager* getSceneManager()
	{
		return getDevice()->getSceneManager();
	}
	static irr::gui::IGUIEnvironment* getGUIEnvironment()
	{
		return getDevice()->getGUIEnvironment();
	}
private:
	static GameApp* singleton;
	irr::IrrlichtDevice* device;

	// returns false if failed to initialize
	void initDevice();
};

} // end namespace vik

#endif // GAMEAPP_HPP_INCLUDED
