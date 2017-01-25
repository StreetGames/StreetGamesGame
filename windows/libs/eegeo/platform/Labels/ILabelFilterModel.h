// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "LabelLayer.h"
#include "ICallback.h"
#include "IModelObserver.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class ILabelFilterModel
        {
        public:
            
            virtual ~ILabelFilterModel()
            {}
            
            virtual void GetLabelLayerIds(std::vector<LabelLayer::IdType>& out_labelLayerIds) const = 0;
            
            virtual void SetLayerEnabled(LabelLayer::IdType labelLayerId, bool enabled) = 0;
            
            virtual bool IsLayerEnabled(LabelLayer::IdType labelLayerId) const = 0;
        };
        
        
        class ILabelFilterModelObserver : public IModelObserver
        {
        public:
            virtual ~ILabelFilterModelObserver() {}

        };
    }
}