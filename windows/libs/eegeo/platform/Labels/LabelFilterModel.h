// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ILabelFilterModel.h"
#include "Types.h"

#include <map>
#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class LabelFilterModel : public ILabelFilterModel, public ILabelFilterModelObserver, private Eegeo::NonCopyable
        {
        public:
            
            LabelFilterModel(const Labels::ILabelLayerRepository& labelLayerRepository);
            
            void GetLabelLayerIds(std::vector<LabelLayer::IdType>& out_labelLayerIds) const;
            
            void SetLayerEnabled(LabelLayer::IdType labelLayerId, bool enabled);
            
            bool IsLayerEnabled(LabelLayer::IdType labelLayerId) const;

            void RegisterChangedCallback(CallbackType& callback);
            
            void UnregisterChangedCallback(CallbackType& callback);
            
        private:
        
            void NotifyChanged() const;
        
            const Labels::ILabelLayerRepository& m_labelLayerRepository;
            
            typedef std::map<LabelLayer::IdType, bool> LayerToDisabledType;
            LayerToDisabledType m_layerToDisabled;
            
            std::vector<CallbackType*> m_callbacks;
        };

    }
}