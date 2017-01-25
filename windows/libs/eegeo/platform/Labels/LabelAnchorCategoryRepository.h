// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ModelRepository.h"
#include "LabelAnchorCategory.h"


namespace Eegeo
{
    namespace Labels
    {
        typedef ModelRepository<LabelAnchorCategory::IdType, const LabelAnchorCategory*> _TLabelAnchorCategoryRepository;
        
        class ILabelAnchorCategoryRepository : public virtual IModelRepository<_TLabelAnchorCategoryRepository::KeyType, _TLabelAnchorCategoryRepository::ItemType, _TLabelAnchorCategoryRepository::IteratorType>
        {
            
        };
        
        class LabelAnchorCategoryRepository : public ILabelAnchorCategoryRepository, public _TLabelAnchorCategoryRepository
        {
            
        };
    }
}