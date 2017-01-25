// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Culling
    {
        struct IndexBufferRange
        {
        public:
            IndexBufferRange(int startIndex, int numOfIndices)
            : m_startIndex(startIndex)
            , m_numOfIndices(numOfIndices)
            {
                
            }

            inline int StartIndex() const { return m_startIndex; }
            inline int NumOfIndices() const { return m_numOfIndices; }
            inline bool IsEmpty() const { return (m_numOfIndices == 0); }
            
        private:
            int m_startIndex;
            int m_numOfIndices;
        };
    }
}