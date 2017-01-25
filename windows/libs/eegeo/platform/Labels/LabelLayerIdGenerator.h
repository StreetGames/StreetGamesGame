// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LabelLayer.h"
#include "Types.h"

namespace Eegeo
{
    namespace Labels
    {
        class ILabelLayerIdGenerator
        {
        public:
            virtual ~ILabelLayerIdGenerator() {}
            virtual LabelLayer::IdType GetNext() = 0;
        };
        
        
        class LabelLayerIdGenerator : public ILabelLayerIdGenerator, private Eegeo::NonCopyable
        {
        public:
            LabelLayerIdGenerator();
            
            LabelLayer::IdType GetNext();
            
        private:
            int m_nextId;
        };
    }
}