#include "viking/GameObject.hpp"

namespace vik
{

GameObject::GameObject(GameObjectFactory* manufacturer):
receipt(this, manufacturer)
{
}

} // end namespace vik
