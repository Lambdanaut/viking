#ifndef GAMETIME_H_INCLUDED
#define GAMETIME_H_INCLUDED

#include "viking/core/types.h"

namespace vik
{

class GameTime
{
public:
	GameTime();

	void Start();
	void Update();

	u32 msDeltaTime() const
	{
		return deltaTime;
	}
private:
	u32 lastTime;
	u32 currentTime;
	u32 deltaTime;
};

} // end namespace vik

#endif // GAMETIME_H_INCLUDED
