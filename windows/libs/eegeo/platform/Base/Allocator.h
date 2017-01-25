// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "TrackingAllocator.h"
#include "AllocationRecord.h"

#include <stdlib.h>

namespace Eegeo
{
	class Allocator
	{
	public:
		Allocator			()	{}
		virtual ~Allocator	()	{}
		
		virtual void*	Alloc		( size_t alignment, size_t size, const char* file, int line)	{ (void)alignment; (void)size; (void)file; (void)line; return NULL; }
		virtual void	Free		( void* data )											{ (void)data; }
	};
    
    Allocator*		GetAllocator		();
    Allocator*		SetAllocator		( Allocator* pAllocator );
    
    Allocator*		GetEndAllocator		();
    Allocator*		SetEndAllocator		( Allocator* pAllocator );
    
    Allocator*		GetDefaultAllocator	();
    
}

namespace Eegeo
{
	
	class Mallocator : public Allocator
	{
	public:
		
#if defined(Eegeo_MEMORY_TRACKING_NEW)
        virtual void* Alloc(size_t alignment, size_t size, const char* file, int line)
        {
            void* payload = TrackingAllocator::PerformAlloc((int)alignment, size);
            AllocationRecord* record = AllocationRecord::GetFromPayload(payload);
            record->site.file = file;
            record->site.line = line;

            return payload;
        }
#elif defined (EEGEO_IOS)
		virtual void*	Alloc		( size_t alignment, size_t size, const char* file, int line )	{ void* pData; posix_memalign(&pData, alignment, size); return pData; }
#elif defined (EEGEO_OSX) || defined (EEGEO_WIN)
        virtual void* Alloc( size_t alignment, size_t size, const char* file, int line )
        {
            void *mem = malloc( size );
            return mem;
        }
#else
		virtual void*	Alloc		( size_t alignment, size_t size, const char* file, int line )	{ void* pData = memalign(alignment, size); return pData; }
#endif

#if defined(Eegeo_MEMORY_TRACKING_NEW)
        virtual void Free(void* data) 
        { 
            TrackingAllocator::PerformFree(data);
        }
#else
		virtual void	Free		( void* data )				{ free(data); }
#endif
	};
	
	extern Allocator*	gAllocator;
	extern Allocator*	gEndAllocator;
	
	static Mallocator defaultAllocator;
}



#define Eegeo_BASE_ALLOC(alloc, align, size)	alloc->Alloc(align, size, __FILE__, __LINE__)
#define Eegeo_BASE_FREE(alloc, data)			alloc->Free(data)

