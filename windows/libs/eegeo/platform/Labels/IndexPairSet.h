// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "Types.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class IndexPairSet
        {
        public:
            IndexPairSet();
            
            void Resize(int maxObjects);
            
            void Clear();
            
            void Shrink();
            
            bool Contains(int objectIndexA, int objectIndexB) const;
            
            void Set(int objectIndexA, int objectIndexB);
            
            bool SetAndReturnDidContain(int objectIndexA, int objectIndexB);
            
        private:
        
            int CalcBitIndex(int objectIndexA, int objectIndexB) const
            {
                Eegeo_ASSERT(objectIndexA != objectIndexB);
                int minIndex = std::min(objectIndexA, objectIndexB);
                int maxIndex = std::max(objectIndexA, objectIndexB);
                
                return (minIndex * (2 * m_maxObjects - minIndex - 3) / 2) + maxIndex - 1;
            }
            
            u32 CalcMask(int bitIndex) const
            {
                return 1 << (bitIndex & 31);
            }
            
            int CalcElementIndex(int bitIndex) const
            {
                return bitIndex >> 5;
            }
            
            bool IsElementSet(int elementIndex, u32 elementMask) const
            {
                return (m_bitfield[elementIndex] & elementMask) != 0;
            }
            
            void SetElement(int elementIndex, u32 elementMask)
            {
                m_bitfield[elementIndex] |= elementMask;
            }
            
            int m_maxObjects;
            std::vector<u32> m_bitfield;
        };
    }
}