#ifndef COREAPP_H_INCLUDED
#define COREAPP_H_INCLUDED

#include "viktypes.h"

namespace vik
{

class CoreApp
{
public:
    CoreApp();
    ~CoreApp();

    void Sleep(u32 ms);
};

} // end namespace vik

#endif // COREAPP_H_INCLUDED
