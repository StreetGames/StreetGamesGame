// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ModelRepository.h"
#include "LabelView.h"


namespace Eegeo
{
    namespace Labels
    {
        typedef ModelRepository<LabelView::IdType, LabelView*> _TLabelViewRepository;
        
        class ILabelViewRepository : public virtual IModelRepository<_TLabelViewRepository::KeyType, _TLabelViewRepository::ItemType, _TLabelViewRepository::IteratorType>
        {
            
        };
        
        class LabelViewRepository : public ILabelViewRepository, public _TLabelViewRepository
        {
            
        };
    }
}