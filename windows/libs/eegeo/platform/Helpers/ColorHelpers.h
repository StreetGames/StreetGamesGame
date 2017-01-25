// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "VectorMath.h"


namespace Eegeo
{
    namespace Helpers
    {
        inline v3 MakeColorRGB(u8 r, u8 g, u8 b)
        {
            v3 color(static_cast<float>(r)/255.f, static_cast<float>(g)/255.f, static_cast<float>(b)/255.f);
            return color;
        }
        
        inline v4 MakeColorRGBA(u8 r, u8 g, u8 b, u8 a)
        {
            v4 color(static_cast<float>(r)/255.f, static_cast<float>(g)/255.f, static_cast<float>(b)/255.f, static_cast<float>(a)/255.f);
            return color;
        }
        
        
        inline v4 RGBA32ToColor(u32 rgba)
        {
            u8 a = rgba & 0xff;
            u8 b = (rgba >> 8) & 0xff;
            u8 g = (rgba >> 16) & 0xff;
            u8 r = (rgba >> 24) & 0xff;
            return MakeColorRGBA(r, g, b, a);
        }
        
        inline u32 MakeColorRGBA32(u8 r, u8 g, u8 b, u8 a)
        {
            u32 rgba32 = (r << 24) | (g << 16) | (b << 8) | a;
            return rgba32;
        }
    }
}