// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Fonts
    {
        namespace BMFont
        {
            struct BMFontCommon
            {
                float lineHeight;
                float base;
                int scaleW;
                int scaleH;
                int pages;
                
                BMFontCommon()
                : lineHeight(0.f)
                , base(0)
                , scaleW(0)
                , scaleH(0)
                , pages(0)
                {
                    
                }
            };
        }
    }
}