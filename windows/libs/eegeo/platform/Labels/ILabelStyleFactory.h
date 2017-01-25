// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include <string>

namespace Eegeo
{
    namespace Labels
    {
        class ILabelStyleFactory
        {
        public:
            virtual ~ILabelStyleFactory() {}
            
            virtual LabelStyle* Create(const LabelStyleDto& labelStyleDto) = 0;
        };
    }
}