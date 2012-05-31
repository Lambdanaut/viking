#ifndef OBJECTFACTORYTAG_HPP_INCLUDED
#define OBJECTFACTORYTAG_HPP_INCLUDED

namespace vik
{

class GameObjectFactory;

// Gives an automatic hook to factories for game objects created by them
class ObjectFactoryTag
{
public:
	ObjectFactoryTag(GameObjectFactory* factory);
	void recall();
private:
	GameObjectFactory* manufacturer;
	GameObject* shipment;
};

} // end namespace vik

#endif // OBJECTFACTORYTAG_HPP_INCLUDED
