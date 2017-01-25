// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "IMaterial.h"
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        struct FontMaterialSetProperties
        {
            FontMaterialSetProperties()
            : IsSdf(false)
            , HasOutline(false)
            , HasHalo(false)
            , HasSupersampling(false)
            , HasNonUniformScale(false)
            {
                
            }
            
            std::string FontInstanceId;
            bool IsSdf;
            bool HasOutline;
            bool HasHalo;
            bool HasSupersampling;
            bool HasNonUniformScale;
            
            bool operator< (const FontMaterialSetProperties& rhs) const
            {
                if (FontInstanceId == rhs.FontInstanceId)
                {
                    return ToFlags() < rhs.ToFlags();
                }
                return FontInstanceId < rhs.FontInstanceId;
            }
        private:
            u32 ToFlags() const
            {
                u32 flags = 0;
                flags += IsSdf ? 0x1 : 0;
                flags += HasOutline ? 0x2 : 0;
                flags += HasHalo ? 0x4 : 0;
                flags += HasSupersampling ? 0x8 : 0;
                flags += HasNonUniformScale ? 0x10 : 0;
                return flags;
            }
        };
    }
}