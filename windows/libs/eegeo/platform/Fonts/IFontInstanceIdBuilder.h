// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"

#include <string>

namespace Eegeo
{
    namespace Fonts
    {
        class IFontInstanceIdBuilder
        {
        public:
            virtual ~IFontInstanceIdBuilder() {;}
            
            virtual std::string Build(const std::string& fontUrl) = 0;
        };
    }
}