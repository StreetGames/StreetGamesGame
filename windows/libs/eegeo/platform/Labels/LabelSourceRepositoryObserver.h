// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Labels.h"
#include "Types.h"

#include "AnchoredLabelSourceRepository.h"
#include "IAnchoredLabelSource.h"
#include "LabelViewFactory.h"
#include "LabelViewRepository.h"
#include "ILabelFilterModel.h"

namespace Eegeo
{
    namespace Labels
    {
        class LabelSourceRepositoryObserver : public IAnchoredLabelSourceRepository::ObserverType, private Eegeo::NonCopyable
        {
        public:
            LabelSourceRepositoryObserver(IAnchoredLabelSourceRepository& labelSourceRepository,
                                          ILabelViewFactory& labelViewFactory,
                                          ILabelViewRepository& labelViewRepository,
                                          const ILabelFilterModel& labelFilterModel,
                                          ILabelFilterModelObserver& labelFilterModelObserver,
                                          const ILabelStyleBindingRepository& labelStyleBindingRepository,
                                          const LabelAnchorCategory::IdType& defaultLineId,
                                          const LabelAnchorCategory::IdType& defaultPointId);
            
            ~LabelSourceRepositoryObserver();
            
            void OnItemAdded(const IAnchoredLabelSourceRepository::ObserverType::ItemType& item);
            
            void OnItemRemoved(const IAnchoredLabelSourceRepository::ObserverType::ItemType& item);
            
        private:
            const LabelStyle::IdType& GetLabelStyleForAnchorCategory(const LabelAnchorCategory& labelAnchorCategory) const;
            
            const LabelAnchorCategory::IdType& GetLabelAnchorCategoryIdOrDefault(const LabelAnchorCategory& labelAnchorCategory) const;
            
            void OnLabelFilterModelChanged();
            
            LabelView* CreateAndAddViewFor(const IAnchoredLabel& anchoredLabel);
            void RemoveAndDestroyViewFor(const IAnchoredLabel& anchoredLabel);
            
            IAnchoredLabelSourceRepository& m_labelSourceRepository;
            ILabelViewFactory& m_labelViewFactory;
            ILabelViewRepository& m_labelViewRepository;
            const ILabelStyleBindingRepository& m_labelStyleBindingRepository;
            const LabelAnchorCategory::IdType& m_defaultLineId;
            const LabelAnchorCategory::IdType& m_defaultPointId;
            std::vector<const IAnchoredLabel*> m_anchoredLabelBuffer;
            const ILabelFilterModel& m_labelFilterModel;
            ILabelFilterModelObserver& m_labelFilterModelObserver;
            Helpers::TCallback0<LabelSourceRepositoryObserver> m_labelFilterModelChanged;
        };
    }
}