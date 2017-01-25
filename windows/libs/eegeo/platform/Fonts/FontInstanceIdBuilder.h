// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "IFontInstanceIdBuilder.h"

namespace Eegeo
{
    namespace Fonts
    {
        class FontInstanceIdBuilder : public IFontInstanceIdBuilder, private Eegeo::NonCopyable
        {
        public:
            std::string Build(const std::string& fontUrl);
        };
    }
}

