#ifndef EVENTSYSTEM_H_INCLUDED
#define EVENTSYSTEM_H_INCLUDED

namespace vik
{

class VikingRoot;

class EventSystem
{
public:
	EventSystem(VikingRoot& root);
	void DispatchEvents();
private:
	VikingRoot& root;
};

} // end namespace vik

#endif // EVENTSYSTEM_H_INCLUDED
