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
        class ILabelAnchorFilter
        {
        public:
            virtual ~ILabelAnchorFilter() {;}
            virtual bool operator()(const IAnchoredLabel& anchoredLabel) const = 0;
        };
        
        template <typename TContext>
        class TLabelAnchorFilter : public ILabelAnchorFilter
        {
        public:
            typedef bool (TContext::*TPredicate)(const IAnchoredLabel& anchoredLabel) const;
            
            TLabelAnchorFilter(TContext* context, TPredicate predicate)
            : m_predicate(predicate)
            , m_pContext(context)
            {
            }
            
            virtual bool operator()(const IAnchoredLabel& anchoredLabel) const
            {
                return (*m_pContext.*m_predicate)(anchoredLabel);
            }
        private:
            TPredicate m_predicate;
            TContext* m_pContext;
        };
        
        
        class ILabelAnchorFilterModel
        {
        public:
            virtual ~ILabelAnchorFilterModel() {}
            
            virtual void SetFilter(LabelLayer::IdType labelLayerId, const ILabelAnchorFilter* pFilter) = 0;
            
            virtual const ILabelAnchorFilter* GetFilter(LabelLayer::IdType labelLayerId) const = 0;
        };
        
        
        bool LableAnchorFilterPredicate(const ILabelAnchorFilterModel& labelAnchorFilterModel, const IAnchoredLabel& anchoredLabel);

        
        class ILabelAnchorFilterModelObserver : public IModelObserver
        {
        public:
            virtual ~ILabelAnchorFilterModelObserver() {}
            
        };
    }
}