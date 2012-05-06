#include "gameobject.h"

namespace vik
{

GameObject::~GameObject()
{
}

void GameObject::Update(u32 dt)
{
}

bool GameObject::OnEvent(Event& e)
{
	return false;
}

} // end namespace vik
