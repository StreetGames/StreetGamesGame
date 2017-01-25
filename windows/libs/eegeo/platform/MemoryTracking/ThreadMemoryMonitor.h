#pragma once

#include "AllocationHashTable.h"
#include "Spinlock.h"
#include "TagStack.h"

#include <fstream>

namespace Eegeo
{
    class MemoryMonitor;

    class ThreadMemoryMonitor
    {
    public:

        ThreadMemoryMonitor(MemoryMonitor& memoryMonitor);
        ~ThreadMemoryMonitor();

        void PushTag(const char* tag);
        void PopTag();
        void AddAllocationRecord(AllocationRecord* record);
        bool RemoveAllocationRecord(AllocationRecord* record, bool canFallBackToGlobal = true);
        bool FindAllocationRecord(AllocationRecord* record, bool canFallBackToGlobal = true);
        void AnnotateAllocation(void* allocation, const char* type, const char* file, int line, int elementCount);
        void DumpAllocationsToCSV(std::fstream& writer);
        void SetNext(ThreadMemoryMonitor* next) { m_next = next; }
        ThreadMemoryMonitor* GetNext() { return m_next; }

        void PauseTracking() { m_trackingPaused = true; }
        void ResumeTracking() { m_trackingPaused = false; }
        bool IsTrackingPaused() const { return m_trackingPaused; }

    private:

        ThreadMemoryMonitor* m_next;
        void* m_threadId;
        Eegeo::SpinLock m_lock;
        bool m_trackingPaused;

        MemoryMonitor& m_memoryMonitor;
        typedef TagStack<32> MemTagStack;
        MemTagStack m_tags;
        size_t m_totalBytesAllocatedOnThread;
        AllocationHashTable m_allocations;
    };
};
