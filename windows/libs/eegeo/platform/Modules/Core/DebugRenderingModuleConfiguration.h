// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include <string>

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            struct DebugRenderingModuleConfiguration
            {
                DebugRenderingModuleConfiguration()
                : InitialLineBufferSize(0)
                , InitialGeomVertexBufferSize(0)
                , InitialGeomIndexBufferSize(0)
                , InitialGlyphBufferSize(0)
                , LineWidth(1.f)
                {};
                
                std::string DebugFontFilename;
                
                int InitialLineBufferSize;
                int InitialGeomVertexBufferSize;
                int InitialGeomIndexBufferSize;
                int InitialGlyphBufferSize;
                float LineWidth;
            };
        }
    }
}