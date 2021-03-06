// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Fonts
    {
        namespace BMFont
        {
            struct BMFontInfo
            {
                std::string face;
                std::string charSet;
                Eegeo::v4 padding;
                Eegeo::v2 spacing;
                int size;
                int stretchH;
                int antiAliasing;
                int outline;
                float sdfSpread;
                bool bold;
                bool italic;
                bool unicode;
                bool smooth;
                bool sdf;
                
                BMFontInfo()
                : padding(v4::Zero())
                , spacing(v2::Zero())
                , size(0)
                , stretchH(0)
                , antiAliasing(0)
                , outline(0)
                , sdfSpread(0.f)
                , bold(false)
                , italic(false)
                , unicode(false)
                , smooth(false)
                , sdf(false)
                {
                    
                }
            };
        }
    }
}