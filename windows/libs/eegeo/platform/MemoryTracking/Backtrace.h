#pragma once

#include <string>
#include "Types.h"

namespace Eegeo
{
    class Backtrace
    {
    public:

        Backtrace();
        void Capture();
        u32 GetStackDepth() const { return m_stackDepth; }
        void* operator[] (const u32 index) { return m_stack[index]; }
        std::string GetSymbolNameAtIndex(u32 index) const;
        std::string GetSymbolicatedStackString(const std::string& separator = "->") const;
        std::string GetRawStackString(const std::string& separator = "->") const;

    private:

        static void OneTimeInit();

        static bool m_isInitialized;
#if defined(EEGEO_WIN)
        static HANDLE m_currentProcess;
#endif
        static const int MaxStackDepth = 32;
        void* m_stack[MaxStackDepth];
        u32 m_stackDepth;
    };
};