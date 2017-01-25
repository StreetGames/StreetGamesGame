#pragma once

#include "Types.h"
#include <stdint.h>

namespace Eegeo
{
    struct AllocationRecord;
    
    class AllocationHashTable
    {
    public:

        AllocationHashTable();

        void AddRecord(Eegeo::AllocationRecord* record);
        bool RemoveRecord(AllocationRecord* target);
        bool FindRecord(AllocationRecord* target, AllocationRecord**& precedingNodeNext);

        u64 GetEntryCount() const;
        u32 GetBinCount() const;
        AllocationRecord* GetBin(u32 index);

    private:

        static u32 GetBinIndex(AllocationRecord* p)
        {
            u32 result;
            
            // :TODO: Replace with std::hash when we go C++11-only.
            // this isn't based on very much evidence, I just needed something fast & it seems to cause a decent spread
            result = static_cast<u32>((((reinterpret_cast<uintptr_t>(p) >> 4) ^ ((u64)0x5FE4C1C2B9B84C09)) * ((u64)0x7E8A101488293D4D)) % BinCount);
            
            return result;
        }

        static const u32 BinCount = 1024;
        AllocationRecord* m_bins[BinCount];
        u64 m_entryCount;
    };
};
