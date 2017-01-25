// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "Rendering.h"

#include <string>

namespace Eegeo
{
    namespace Fonts
    {
        class FontMaterialSetBuilder : private Eegeo::NonCopyable
        {
        public:
            FontMaterialSetBuilder(Rendering::Materials::ITextMaterialFactory& textMaterialFactory);
            
            void Reset();
            
            FontMaterialSet* Build();
            
            FontMaterialSetBuilder& SetName(const std::string& name);
            
            FontMaterialSetBuilder& SetFontInstance(const Fonts::FontInstance& fontInstance);
            
            FontMaterialSetBuilder& SetOutline(bool needsOutline);
            
            FontMaterialSetBuilder& SetSdfHalo(bool needsSdfHalo);
            
            FontMaterialSetBuilder& SetSupersampling(bool needsSupersampling);
            
            FontMaterialSetBuilder& SetNonUniformScale(bool needsNonUniformScale);

        private:
            Rendering::Materials::ITextMaterialFactory& m_textMaterialFactory;
            std::string m_name;
            const Fonts::FontInstance* m_pFontInstance;
            bool m_needsOutline;
            bool m_needsSdfHalo;
            bool m_needsSupersampling;
            bool m_needsNonUniformScale;
        };
    }
}