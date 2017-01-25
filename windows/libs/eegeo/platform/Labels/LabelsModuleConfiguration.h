// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "Labels.h"
#include "VectorMath.h"
#include <string>

namespace Eegeo
{
    namespace Labels
    {
        struct LabelsModuleConfiguration
        {
            LabelsModuleConfiguration()
            : ReferenceViewportDimensions(v2::Zero())
            , ReferenceViewportPPI(0.f)
            , NominalPxPerInch(0.f)
            , CustomTextScale(0.f)
            {
                
            }
            
            std::string StyleSheetPath;
            v2 ReferenceViewportDimensions;
            float ReferenceViewportPPI;
            float NominalPxPerInch;
            float CustomTextScale;
        };
    }
}