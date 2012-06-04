#ifndef REFERENCECOUNTED_HPP_INCLUDED
#define REFERENCECOUNTED_HPP_INCLUDED

#include <irrlicht/irrTypes.h>
#include <cassert>

namespace vik
{

// automatically deletes objects inheriting from this when they reach a reference count of 0
// they start with a count of 1. grab increases the count, drop reduces it.
// this is a rudimentary lightweight implementation of shared pointers
// it does not handle complex scenarios like cyclic dependencies. Be sure to use this safely.
// If the scenario is too complicated, consider:
// A) Redesigning your mess because apparently you don't even know the lifetime of your own crap
// B) Using a more elaborate reference counting mechanism, such as std::shared_ptr from the <memory> header
class ReferenceCounted
{
public:
	inline ReferenceCounted();
	virtual ~ReferenceCounted(){}

	// increment reference count (essentially a request to share ownership)
	inline void grabReference() const;
	// decrement reference and delete object if the reference count falls to 0
	inline bool dropReference() const;

	// returns number of references this object has
	inline irr::s32 getReferenceCount() const;
private:
	mutable irr::s32 referenceCount;
};

ReferenceCounted::ReferenceCounted():
referenceCount(1)
{
}

void ReferenceCounted::grabReference() const
{
	++referenceCount;
}

bool ReferenceCounted::dropReference() const
{
	assert(referenceCount >= 1);
	
	--referenceCount;
	if (!referenceCount)
	{
		delete this;
		return true;
	}
	return false;
}

inline irr::s32 ReferenceCounted::getReferenceCount() const
{
	return referenceCount;
}

} // end namespace vik

#endif // REFERENCECOUNTED_HPP_INCLUDED
