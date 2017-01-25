// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"

namespace Eegeo
{
    namespace Labels
    {
        class ILabelTextStyleFactory
        {
        public:
            virtual ~ILabelTextStyleFactory() {}
            
            virtual LabelTextStyle* Create(const LabelTextStyleDto& LabelTextStyleDto) = 0;
        };
    }
}