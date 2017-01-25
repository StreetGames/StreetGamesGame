// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"

#include <string>

namespace Eegeo
{
    namespace Labels
    {
        class LabelLayer : private Eegeo::NonCopyable
        {
        public:
            typedef int IdType;
            
            LabelLayer(IdType labelLayerId, const std::string& labelLayerName);
            
            IdType GetId() const { return m_labelLayerId; }
            
            const std::string& GetLabelLayerName() const { return m_labelLayerName; }
            
        private:
            const LabelLayer::IdType m_labelLayerId;
            const std::string m_labelLayerName;
        };
    }
}