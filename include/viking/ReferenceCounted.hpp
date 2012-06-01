#ifndef REFERENCECOUNTED_HPP_INCLUDED
#define REFERENCECOUNTED_HPP_INCLUDED

#include <irrlicht/irrTypes.h>
#include <cassert>

namespace vik
{

// automatically deletes objects inheriting from this when they reach a reference count of 0
// they start with a count of 1. grab increases the count, drop reduces it.
class ReferenceCounted
{
public:
	inline ReferenceCounted();
	virtual ~ReferenceCounted(){}

	inline void grabReference() const;
	inline bool dropReference() const;

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
