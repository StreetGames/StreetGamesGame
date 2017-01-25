// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ModelRepository.h"
#include "LabelStyle.h"


namespace Eegeo
{
    namespace Labels
    {
        typedef ModelRepository<LabelStyle::IdType, const LabelStyle*> _TLabelStyleRepository;
        
        class ILabelStyleRepository : public virtual IModelRepository<_TLabelStyleRepository::KeyType, _TLabelStyleRepository::ItemType, _TLabelStyleRepository::IteratorType>
        {
            
        };
        
        class LabelStyleRepository : public ILabelStyleRepository, public _TLabelStyleRepository
        {
            
        };
    }
}