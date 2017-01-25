#pragma once

#include "Types.h"

#if defined(EEGEO_IOS)  || defined(EEGEO_OSX)
#include <malloc/malloc.h>
#endif

namespace Eegeo
{
    // doesn't really have any business being a class, just trying to divvy stuff up atm
    class SystemAllocator
    {
    public:

        static void Init();

        static void* Malloc(size_t size);
        static void* Realloc(void* ptr, size_t size);
        static void Free(void* ptr);
        static void FreeDefiniteSize(void *ptr, size_t size);
        static void* Calloc(size_t num_items, size_t size);
        static void* MemAlign(size_t alignment, size_t size);

        static int GetDefaultAlignment();

#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
        static void* Valloc(size_t size);
        static size_t Size(const void *ptr);
#endif

    private:

#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
        static malloc_zone_t* ms_systemImplementation;
#endif
        
        static const int m_defaultAlignment;
    };

};