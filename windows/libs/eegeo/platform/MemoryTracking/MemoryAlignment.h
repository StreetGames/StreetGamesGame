#pragma once

#include "Types.h"

namespace Eegeo
{
    class MemoryAlignment
    {
    public:

        inline static void* AlignDown(const void* _input, uint32_t _alignment)
        {
            return reinterpret_cast<uint8_t*>(reinterpret_cast<const uintptr_t>(_input) & ~static_cast<uintptr_t>(_alignment - 1));
        }

        inline static void* AlignUp(const void* _input, uint32_t _alignment)
        {
            return AlignDown(reinterpret_cast<const uint8_t*>(_input) + _alignment - 1, _alignment);
        }
    };
};