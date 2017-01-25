// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "Types.h"
#include "Labels.h"
#include "ModelRepository.h"
#include "LabelResourceFontBinding.h"


namespace Eegeo
{
    namespace Labels
    {
        typedef ModelRepository<LabelResource::Type, const LabelResourceFontBinding*> _TLabelResourceFontBindingRepository;
        
        class ILabelResourceFontBindingRepository : public virtual IModelRepository<_TLabelResourceFontBindingRepository::KeyType, _TLabelResourceFontBindingRepository::ItemType, _TLabelResourceFontBindingRepository::IteratorType>
        {
            
        };
        
        class LabelResourceFontBindingRepository : public ILabelResourceFontBindingRepository, public _TLabelResourceFontBindingRepository
        {
            
        };
    }
}