// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ModelRepository.h"
#include "LabelStyleBinding.h"


namespace Eegeo
{
    namespace Labels
    {
        typedef ModelRepository<LabelStyleBinding::LabelAnchorCategoryId, const LabelStyleBinding*> _TLabelStyleBindingRepository;
        
        class ILabelStyleBindingRepository : public virtual IModelRepository<_TLabelStyleBindingRepository::KeyType, _TLabelStyleBindingRepository::ItemType, _TLabelStyleBindingRepository::IteratorType>
        {
            
        };
        
        class LabelStyleBindingRepository : public ILabelStyleBindingRepository, public _TLabelStyleBindingRepository
        {
            
        };
    }
}