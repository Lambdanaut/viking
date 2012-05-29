#ifndef STATE_HPP_INCLUDED
#define STATE_HPP_INCLUDED

namespace vik
{

template<class T>
class State
{
public:
	State(T* context);
	virtual ~State(){}

	// get pointer to entity acted upon by the state
	T* getContext(){ return context; }
	const T* getContext() const { return context; }

	// functions to override in derived classes
	virtual void onEnter() = 0;
	virtual void onUpdate(irr::f32 dt) = 0;
	virtual void onLeave() = 0;
private:
	T* context;
};

} // end namespace vik

#endif // STATE_HPP_INCLUDED
