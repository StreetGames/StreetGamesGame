// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "IOcclusionResolver.h"
#include "Types.h"
#include "IndexPairSet.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class SweptAxisOcclusionResolver : public IOcclusionResolver, private Eegeo::NonCopyable
        {
        public:
            SweptAxisOcclusionResolver(OcclusionResolverMode::Type occlusionMode);
            
            void Clear();
            
            void Shrink();
        
            InputListType& InputList() { return m_inputList; }
            
            void Resolve(const IOcclusionIntersectionPredicate& intersectionPredicate);
            
            const ResultsListType& GetResults() const { return m_resultsList; }
            
            void SetMode(OcclusionResolverMode::Type occlusionMode) { m_occlusionMode = occlusionMode; }
           
        private:
            void PopulateDisabledOcclusionResults();
            
            InputListType m_inputList;
            ResultsListType m_resultsList;
            std::vector<u16> m_inputOrderedByPriority;
            std::vector<u16> m_inputOrderedByMinY;
            std::vector<u16> m_inputMinYOrdinal;
            std::vector<u8> m_inputIsOccluded;
            
            IndexPairSet m_indexPairSet;
            
            OcclusionResolverMode::Type m_occlusionMode;
        };
    }
}