#pragma once

#include <fstream>
#include <string>

#include "Spinlock.h"

namespace Eegeo
{
    namespace Helpers
    {
        class IFileIO;
    };

    class ThreadMemoryMonitor;
    struct AllocationRecord;

    class MemoryMonitor
    {
    public:

        MemoryMonitor();

        void RegisterThreadMonitor(ThreadMemoryMonitor* monitor);
        void UnregisterThreadMonitor(ThreadMemoryMonitor* monitor);

        bool RemoveAllocationRecordFromDifferentThread(ThreadMemoryMonitor* excludedMonitor, AllocationRecord* record);
        bool FindAllocationRecordFromDifferentThread(ThreadMemoryMonitor* excludedMonitor, AllocationRecord* record);

        uint64_t GenerateNextAllocationIndex();

        static ThreadMemoryMonitor& GetMemoryMonitorForThread();
        static MemoryMonitor& GetGlobalMemoryMonitor();

        void Report(Eegeo::Helpers::IFileIO& fileIO, const char* outputPath);

    private:

#if defined(EEGEO_WIN)
        volatile LONGLONG m_allocationIndexGenerator;
#else
        volatile int64_t m_allocationIndexGenerator;
#endif
        ThreadMemoryMonitor* m_firstThreadMonitor;
        Eegeo::SpinLock m_globalLock;
    };
};
