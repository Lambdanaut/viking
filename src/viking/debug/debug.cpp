#include "viking/debug/debug.h"

#include <cstdarg>
#include <cassert>
#include <cstdio>

namespace vik
{

void _DebugPrintf(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

void _Assert(bool exp, const char* error_msg_fmt, ...)
{
    if(!exp)
    {
        va_list args;
        va_start(args, error_msg_fmt);
        DebugPrintf(error_msg_fmt, args);
        va_end(args);

        assert(false);
    }
}

} // end namespace vik
