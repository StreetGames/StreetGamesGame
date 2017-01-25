// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "Types.h"
#include "IAnchoredLabelSource.h"
#include "ModelRepository.h"

namespace Eegeo
{
    namespace Labels
    {
        typedef ModelRepository<IAnchoredLabelSource::IdType, const IAnchoredLabelSource*> _TAnchoredLabelSourceRepository;
        
        class IAnchoredLabelSourceRepository : public virtual IModelRepository<_TAnchoredLabelSourceRepository::KeyType, _TAnchoredLabelSourceRepository::ItemType, _TAnchoredLabelSourceRepository::IteratorType>
        {
            
        };
        
        class AnchoredLabelSourceRepository : public IAnchoredLabelSourceRepository, public _TAnchoredLabelSourceRepository
        {
            
        };
    }
}