#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include "viking/core/types.h"

namespace vik
{

class App
{
public:
    App();
    ~App();

    void Sleep(u32 ms);
};

} // end namespace vik

#endif // APP_H_INCLUDED
