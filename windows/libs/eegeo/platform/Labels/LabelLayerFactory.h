// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LabelLayer.h"
#include "Types.h"

namespace Eegeo
{
    namespace Labels
    {
        class ILabelLayerFactory
        {
        public:
            virtual ~ILabelLayerFactory() {}
            virtual LabelLayer* Create(const std::string& labelLayerName) = 0;
        };
        
        class LabelLayerFactory : public ILabelLayerFactory, private Eegeo::NonCopyable
        {
        public:
            LabelLayerFactory(ILabelLayerIdGenerator& labelLayerIdGenerator);
            
            LabelLayer* Create(const std::string& labelLayerName);
        private:
            ILabelLayerIdGenerator& m_labelLayerIdGenerator;
        };
    }
}