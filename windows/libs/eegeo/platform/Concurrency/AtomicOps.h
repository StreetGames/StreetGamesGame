// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
#include <libkern/OSAtomic.h>
#elif defined(EEGEO_WIN)
#include "EegeoWindowsGuard.h"
#endif

namespace Eegeo
{
    namespace Concurrency
    {
        inline bool AtomicCompareAndSwap32(s32 oldValue, s32 newValue, volatile s32* theValue)
        {
#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
            return OSAtomicCompareAndSwap32Barrier((int32_t)oldValue, (int32_t)newValue, (volatile int32_t*)theValue);
#elif defined EEGEO_DROID || defined(EMSCRIPTEN)
            return __sync_bool_compare_and_swap(theValue, oldValue, newValue);
#elif defined EEGEO_WIN
			return InterlockedCompareExchange((volatile long*)theValue, (long)newValue, (long)oldValue) == oldValue;
#endif
        }
        
        inline s32 AtomicIncrement32(volatile s32* theValue)
        {
            // return new value after increment
#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
            return OSAtomicIncrement32Barrier((volatile int32_t*)theValue);
#elif defined EEGEO_DROID || defined(EMSCRIPTEN)
            return __sync_fetch_and_add(theValue, (s32)1);
#elif defined EEGEO_WIN
            return InterlockedIncrement((LONG volatile *)theValue);
#endif
        }
        
        inline s32 AtomicDecrement32(volatile s32* theValue)
        {
            // return new value after decrement
#if defined(EEGEO_IOS) || defined(EEGEO_OSX)
            return OSAtomicDecrement32Barrier((volatile int32_t*)theValue);
#elif defined EEGEO_DROID || defined(EMSCRIPTEN)
            return __sync_fetch_and_sub(theValue, (s32)1);
#elif defined EEGEO_WIN
            return InterlockedDecrement((LONG volatile *)theValue);
#endif
        }
    }
}
