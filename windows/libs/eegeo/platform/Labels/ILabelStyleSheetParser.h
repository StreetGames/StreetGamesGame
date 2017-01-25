// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "LabelStyle.h"
#include "LabelResourceFontBinding.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Labels
    {
    
        struct LabelTextStyleDto
        {
            std::string Name;
            LabelResource::Type LabelResourceFontBinding;
            float SizePx;
            u32 GlyphColorRGBA;
            u32 HaloColorRGBA;
            u32 MaskedGlyphColorRGBA;
            u32 MaskedHaloColorRGBA;
            float HaloWidth;
            float HaloHardness;
            bool ApplyProjectionScale;
        };
        
        struct LabelStyleDto
        {
            std::string Name;
            std::string LabelTextStyleName;
            LabelOrientation::Type LabelOrientation;
            LabelDisplay::Type LabelDisplay;
            LabelHorizontalAlignment::Type LabelHorizontalAlignment;
            LabelVerticalAlignment::Type LabelVerticalAlignment;
            float XOffsetEms;
            float YOffsetEms;
            float AltitudeOffset;
            float ConstraintRadiusScale;
            float FadeDuration;
            bool InitiallyFadedOut;
            StencilMode::Type StencilMode;
            StencilMode::Type StencilModeFlattened;
            int Priority;
        };
        
        
        struct LabelStyleBindingDto
        {
            std::string LabelAnchorCategory;
            std::string LabelStyleName;
        };
        
        struct LabelStyleSheetParserResult
        {
            std::vector<LabelTextStyleDto> LabelTextStyles;
            std::vector<LabelStyleDto> LabelStyles;
            std::vector<LabelStyleBindingDto> LabelStyleBindings;
        };
    
        class ILabelStyleSheetParser
        {
        public:
            virtual ~ILabelStyleSheetParser() {}
            
            virtual bool TryParse(const std::string& serializedLabelStyleSheet, LabelStyleSheetParserResult& out_result) const = 0;
        };
    }
}