#pragma once

#include "Types.h"

#if defined(Eegeo_MEMORY_TRACKING_NEW)
#define Eegeo_SCOPED_MEM_TAG(x) Eegeo::ScopedMemoryTag tag(x)
#else
#define Eegeo_SCOPED_MEM_TAG(x) 
#endif

namespace Eegeo
{

    class ScopedMemoryTag
    {
    public:

        ScopedMemoryTag(const char* tag);
        ~ScopedMemoryTag();
    };

};