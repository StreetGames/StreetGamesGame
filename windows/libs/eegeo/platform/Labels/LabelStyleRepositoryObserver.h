// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ModelRepository.h"
#include "LabelStyle.h"
#include "IModelObserver.h"
#include "LabelStyleRepository.h"

namespace Eegeo
{
    namespace Labels
    {
        class ILabelStyleRepositoryObserver : public IModelObserver
        {
        };

        class LabelStyleRepositoryObserver : public ILabelStyleRepositoryObserver, public ILabelStyleRepository::ObserverType, private Eegeo::NonCopyable
        {
        public:
            LabelStyleRepositoryObserver(ILabelStyleRepository& labelStyleRepository);
            
            ~LabelStyleRepositoryObserver();
            
            void OnItemAdded(const ItemType& item);
            
            void OnItemRemoved(const ItemType& item);
            
            void RegisterChangedCallback(CallbackType& callback);
            
            void UnregisterChangedCallback(CallbackType& callback);
        private:
            void NotifyChanged() const;
            
            ILabelStyleRepository& m_labelStyleRepository;
            
            Helpers::CallbackCollection0 m_callbacks;
        };
        
        
        
    }
}