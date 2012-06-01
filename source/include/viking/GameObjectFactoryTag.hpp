#ifndef GAMEOBJECTFACTORYTAG_HPP_INCLUDED
#define GAMEOBJECTFACTORYTAG_HPP_INCLUDED

namespace vik
{

class GameObjectFactory;
class GameObject;

// Used to give game object factories a hook to handle the end of lifetime of game objects
class GameObjectFactoryTag
{
public:
	GameObjectFactoryTag(GameObject* shipment, GameObjectFactory* manufacturer);

	// gives a signal to the manufacturer that the shipment needs to be recycled
	~GameObjectFactoryTag();
private:
	GameObjectFactory* manufacturer;
	GameObject* shipment;
};

} // end namespace vik

#endif // GAMEOBJECTFACTORYTAG_HPP_INCLUDED
