#ifndef REFCOUNTED_H_INCLUDED
#define REFCOUNTED_H_INCLUDED

#include "viktypes.h"
#include "vikdebug.h"

namespace vik
{

class ReferenceCounted
{
    ReferenceCounted():
    refCount(1)
    {
    }

    virtual ~ReferenceCounted()
    {
    }

    void Grab() const
    {
        ++refCount;
    }

    void Drop() const
    {
        if(--refCount == 0)
        {
            delete this;
        }
    }

    u32 GetReferenceCount() const
    {
        return refCount;
    }
private:
    mutable u32 refCount;
};

} // end namespace vik

#endif // REFCOUNTED_H_INCLUDED
