// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ResourceObserver.h"


namespace Eegeo
{
    namespace Labels
    {
        class ILabelCellResourceObserver : public virtual IResourceObserver<LabelCellResource>
        {

        };
        
        class LabelCellResourceObserver : public ILabelCellResourceObserver, public ResourceObserver<LabelCellResource>
        {
            
        };


    }
}