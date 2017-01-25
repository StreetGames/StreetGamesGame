// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "BuiltResourceWithKey.h"
#include "Types.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class LabelCellResource : public Resources::BuiltResourceWithKey, private Eegeo::NonCopyable
        {
        public:
            LabelCellResource(const Streaming::MortonKey& cellKey,
                              const std::vector<const LabelCellModel*> labelCellModels,
                              ILabelCellResourceObserver& labelCellResourceObserver);
            
            virtual ~LabelCellResource();
            
            virtual void Unload();
            
            virtual void AddedToSceneGraph();
            
            virtual void RemovedFromSceneGraph();
            
            virtual const std::vector<const LabelCellModel*>& GetLabelCellModels() const { return m_labelCellModels; }
            
        private:
            std::vector<const LabelCellModel*> m_labelCellModels;
            ILabelCellResourceObserver& m_labelCellResourceObserver;
        };
    }

}