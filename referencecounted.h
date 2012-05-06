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

    void grab()
    {
        ++refcount;
    }

    void drop()
    {
        if(--refcount == 0)
        {
            delete this;
        }
    }
private:
    u32 refcount;
};

} // end namespace vik

#endif // REFCOUNTED_H_INCLUDED
