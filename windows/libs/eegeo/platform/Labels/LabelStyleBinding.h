// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "Labels.h"
#include "LabelAnchorCategory.h"
#include "LabelStyle.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class LabelStyleBinding : private Eegeo::NonCopyable
        {
        public:
            typedef LabelAnchorCategory::IdType LabelAnchorCategoryId;
            typedef LabelStyle::IdType LabelStyleId;
            
            inline static LabelStyleBinding* Create(const LabelAnchorCategoryId& labelAnchorCategory, const LabelStyleId& labelStyleId);
            
            const LabelAnchorCategoryId& GetLabelAnchorCategoryId() const { return m_labelAnchorCategoryId; }
            
            const LabelStyleId& GetLabelStyleId() const { return m_labelStyleId; }
        
        private:
            LabelStyleBinding(const LabelAnchorCategoryId& labelAnchorCategoryId, const LabelStyleId& labelStyleId)
            : m_labelAnchorCategoryId(labelAnchorCategoryId)
            , m_labelStyleId(labelStyleId)
            {}
            
            LabelAnchorCategoryId m_labelAnchorCategoryId;
            LabelStyleId m_labelStyleId;
        };
        
        
        inline LabelStyleBinding* LabelStyleBinding::Create(const LabelAnchorCategoryId& labelAnchorCategoryId, const LabelStyleId& labelStyleId)
        {
            return Eegeo_NEW(LabelStyleBinding)(labelAnchorCategoryId, labelStyleId);
        }
    }
}