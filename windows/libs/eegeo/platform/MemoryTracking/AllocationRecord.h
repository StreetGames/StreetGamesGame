#pragma once

#include "Types.h"
#include "AllocationSite.h"
#include "Backtrace.h"

namespace Eegeo
{
    struct AllocationRecord
    {
        AllocationRecord(size_t _size, int _alignment);
        void* GetPayload();
        
        static AllocationRecord* GetFromPayload(void* payload);
        static void SetRecordForPayload(void* payload, AllocationRecord* record);
        static size_t GetTotalSizeRequired(size_t payloadSize, int payloadAlignment);
        
        u64 allocationIndex;
        size_t size;
        int alignment;

        AllocationSite site;
        const char* tag;
        void* threadId;
        int elementCount;

        Backtrace trace;
        AllocationRecord* next;
    };

};