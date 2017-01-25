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
        class LabelTextStyle : public Eegeo::NonCopyable
        {
        public:
            typedef std::string IdType;
            
            LabelTextStyle(const IdType& idType,
                           const Fonts::FontInstance& fontInstance,
                           float sizePx,
                           const v4& glyphColor,
                           const v4& haloColor,
                           const v4& maskedGlyphColor,
                           const v4& maskedHaloColor,
                           float haloWidth,
                           float haloHardness);
            
            const IdType& GetId() const { return m_id; }
            const Fonts::FontInstance& GetFontInstance() const { return m_fontInstance; }
            float GetSize() const { return m_sizePx; }
            v4 GetGlyphColor() const { return m_glyphColor; }
            v4 GetHaloColor() const { return m_haloColor; }
            v4 GetMaskedGlyphColor() const { return m_maskedGlyphColor; }
            v4 GetMaskedHaloColor() const { return m_maskedHaloColor; }
            float GetHaloWidth() const { return m_haloWidth; }
            float GetHaloHardness() const { return m_haloHardness; }
            float GetFontScale() const { return m_fontScale; }
            
        private:
            v4 m_glyphColor;
            v4 m_haloColor;
            v4 m_maskedGlyphColor;
            v4 m_maskedHaloColor;
            float m_sizePx;
            float m_haloWidth;
            float m_haloHardness;
            float m_fontScale;
            const Fonts::FontInstance& m_fontInstance;
            IdType m_id;
        };
    }
}