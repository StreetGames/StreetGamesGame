// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "Labels.h"
#include "ModelRepository.h"
#include "LabelTextStyle.h"


namespace Eegeo
{
    namespace Labels
    {
        typedef ModelRepository<LabelTextStyle::IdType, const LabelTextStyle*> _TLabelTextStyleRepository;
        
        class ILabelTextStyleRepository : public virtual IModelRepository<_TLabelTextStyleRepository::KeyType, _TLabelTextStyleRepository::ItemType, _TLabelTextStyleRepository::IteratorType>
        {
            
        };
        
        class LabelTextStyleRepository : public ILabelTextStyleRepository, public _TLabelTextStyleRepository
        {
            
        };
    }
}