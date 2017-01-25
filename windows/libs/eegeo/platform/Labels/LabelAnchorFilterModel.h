// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ILabelAnchorFilter.h"
#include "Types.h"

#include <unordered_map>
#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class LabelAnchorFilterModel : public ILabelAnchorFilterModel, public ILabelAnchorFilterModelObserver, private Eegeo::NonCopyable
        {
        public:
            LabelAnchorFilterModel();
            
            ~LabelAnchorFilterModel();
            
            void SetFilter(LabelLayer::IdType labelLayerId, const ILabelAnchorFilter* pFilter);
            
            const ILabelAnchorFilter* GetFilter(LabelLayer::IdType labelLayerId) const;
            
            void RegisterChangedCallback(CallbackType& callback);
            
            void UnregisterChangedCallback(CallbackType& callback);
        
        private:

            void NotifyChanged() const;
            
            typedef std::unordered_map<LabelLayer::IdType, const ILabelAnchorFilter*> LayerIdToFilter;
            typedef std::vector<CallbackType*> CallbackVector;
            
            LayerIdToFilter m_layerIdToFilter;
            
            CallbackVector m_callbacks;
        };
    }
}