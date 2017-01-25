// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "Text.h"
#include "Fonts.h"
#include "VectorMath.h"

#include <string>

namespace Eegeo
{
    namespace Labels
    {
        namespace LabelOrientation
        {
            enum Type
            {
                Screen,
                MapFeature,
                MapFeatureAutoUpright
            };
        }
        
        namespace LabelDisplay
        {
            enum Type
            {
                ScreenSpace,
                WorldSpaceUpright
            };
        }
        
        namespace LabelHorizontalAlignment
        {
            enum Type
            {
                LeadingGlyph,
                Left,
                Center,
                Right
            };
        }
        
        namespace LabelVerticalAlignment
        {
            enum Type
            {
                Baseline,
                Bottom,
                Middle,
                Top
            };
        }
        
        namespace StencilMode
        {
            enum Type
            {
                Always,
                IfNotMaskedByMapFeature,
                IfMaskedByMapFeature,
                WithMaskedStyle
            };
        }
        

        
        class LabelStyle : public Eegeo::NonCopyable
        {
        public:
            typedef std::string IdType;
            
            LabelStyle(const IdType& labelStyleId,
                       const LabelTextStyle& labelTextStyle,
                       LabelOrientation::Type labelOrientation,
                       LabelDisplay::Type labelDisplay,
                       LabelHorizontalAlignment::Type labelHorizontalAlignment,
                       LabelVerticalAlignment::Type labelVerticalAlignment,
                       const v2& labelOffsetEms,
                       float labelAltitudeOffset,
                       float constraintRadiusScale,
                       float fadeDuration,
                       bool initiallyFadedOut,
                       StencilMode::Type stencilMode,
                       StencilMode::Type stencilModeFlattened,
                       int priority
                       );
            
            IdType GetId() const { return m_id; }
            
            const LabelTextStyle& GetTextStyle() const { return m_labelTextStyle; }
            
            LabelOrientation::Type GetLabelOrientation() const { return m_labelOrientation; }

            LabelDisplay::Type GetLabelDisplay() const { return m_labelDisplay; }

            LabelHorizontalAlignment::Type GetLabelHorizontalAlignment() const { return m_labelHorizontalAlignment; }

            LabelVerticalAlignment::Type GetLabelVerticalAlignment() const { return m_labelVerticalAlignment; }
            
            const v2& GetLabelOffsetEms() const { return m_labelOffsetEms; }
            
            float GetLabelAltitudeOffset() const { return m_labelAltitudeOffset; }

            float GetConstraintRadiusScale() const { return m_constraintRadiusScale; }
            
            float GetFadeDuration() const { return m_fadeDuration; }
            
            bool ShouldFade() const { return m_fadeDuration > 0.f; }
            
            float GetFadeSpeed() const { return m_fadeSpeed; }
            
            bool IsInitiallyFadedOut() const { return m_initiallyFadedOut; }
            
            int GetPriority() const { return m_priority; }
            
            StencilMode::Type GetStencilMode() const { return m_stencilMode; }
            
            StencilMode::Type GetStencilModeFlattened() const { return m_stencilModeFlattened; }
        private:
            const IdType m_id;
            const LabelTextStyle& m_labelTextStyle;
            const LabelOrientation::Type m_labelOrientation;
            const LabelDisplay::Type m_labelDisplay;
            const LabelHorizontalAlignment::Type m_labelHorizontalAlignment;
            const LabelVerticalAlignment::Type m_labelVerticalAlignment;
            const v2 m_labelOffsetEms;
            const float m_labelAltitudeOffset;
            const float m_constraintRadiusScale;
            const float m_fadeDuration;
            const float m_fadeSpeed;
            const StencilMode::Type m_stencilMode;
            const StencilMode::Type m_stencilModeFlattened;
            const bool m_initiallyFadedOut;
            const int m_priority;
            
        };
    }
}