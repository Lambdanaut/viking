#ifndef REFCOUNTED_H_INCLUDED
#define REFCOUNTED_H_INCLUDED

#include "viktypes.h"
#include "vikdebug.h"

namespace vik
{

class ReferenceCounted
{
    ReferenceCounted():
    refcount(1)
    {
    }

    virtual ~ReferenceCounted()
    {
    }

    void grab() const
    {
        ++refcount;
    }

    void drop() const
    {
        if(--refcount == 0)
        {
            delete this;
        }
    }

    u32 reference_count() const
    {
        return refcount;
    }
private:
    mutable u32 refcount;
};

} // end namespace vik

#endif // REFCOUNTED_H_INCLUDED
