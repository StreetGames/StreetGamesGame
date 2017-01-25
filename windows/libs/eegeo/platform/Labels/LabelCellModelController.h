// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"

#include "LabelCellResourceObserver.h"

namespace Eegeo
{
    namespace Labels
    {
        //! notified of scenegraph additions / removals of LabelCellResource instances, maintains repository
        class LabelCellModelController : public Eegeo::NonCopyable
        {
        public:
            LabelCellModelController(ILabelCellResourceObserver& labelCellResourceObserver,
                                     IAnchoredLabelSourceRepository& labelSourceRepository);
            
            ~LabelCellModelController();
        
        private:
            void HandleLabelCellResourceAddedToSceneGraph(const LabelCellResource& resource);
            void HandleLabelCellResourceRemovedFromSceneGraph(const LabelCellResource& resource);
        
            typedef Helpers::TCallback1<LabelCellModelController, ILabelCellResourceObserver::CallbackParamType> TLabelCellResourceObserverCallback;
        
            ILabelCellResourceObserver& m_labelCellResourceObserver;
            IAnchoredLabelSourceRepository& m_labelSourceRepository;
            
            TLabelCellResourceObserverCallback m_labelCellResourceAddedToSceneGraphCallback;
            TLabelCellResourceObserverCallback m_labelCellResourceRemovedFromSceneGraphCallback;
        };
    }
}