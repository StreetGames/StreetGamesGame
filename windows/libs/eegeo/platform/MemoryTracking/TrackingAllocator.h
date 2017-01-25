#pragma once

#include "Types.h"

#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
#include <malloc/malloc.h>
#endif

namespace Eegeo
{
    class TrackingAllocator
    {
    public:

        static void* PerformAlloc(int alignment, size_t size);
        static void PerformFree(void* ptr);
    };
};