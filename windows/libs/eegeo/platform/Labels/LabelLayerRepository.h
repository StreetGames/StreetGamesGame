// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ModelRepository.h"
#include "LabelLayer.h"


namespace Eegeo
{
    namespace Labels
    {
        typedef ModelRepository<LabelLayer::IdType, LabelLayer*> _TLabelLayerRepository;
        
        class ILabelLayerRepository : public virtual IModelRepository<_TLabelLayerRepository::KeyType, _TLabelLayerRepository::ItemType, _TLabelLayerRepository::IteratorType>
        {
            
        };
        
        class LabelLayerRepository : public ILabelLayerRepository, public _TLabelLayerRepository
        {
            
        };
    }
}