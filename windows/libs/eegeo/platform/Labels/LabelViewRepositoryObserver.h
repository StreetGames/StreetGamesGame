// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Labels.h"
#include "Types.h"

#include "LabelViewRepository.h"

namespace Eegeo
{
    namespace Labels
    {
        class LabelViewRepositoryObserver : public ILabelViewRepository::ObserverType, private Eegeo::NonCopyable
        {
        public:
            LabelViewRepositoryObserver(ILabelViewRepository& labelViewRepository);
            
            ~LabelViewRepositoryObserver();
            
            void OnItemAdded(const ILabelViewRepository::ObserverType::ItemType& item)
            {
                m_repositoryChanged = true;
            }
            
            void OnItemRemoved(const ILabelViewRepository::ObserverType::ItemType& item)
            {
                m_repositoryChanged = true;
            }
            
            bool HasChanged() const
            {
                return m_repositoryChanged;
            }
            
            void Reset()
            {
                m_repositoryChanged = false;
            }
            
        private:
            ILabelViewRepository& m_labelViewRepository;
            bool m_repositoryChanged;
        };
    }
}