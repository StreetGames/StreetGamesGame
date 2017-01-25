// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IFontMaterialSetFactory.h"
#include "Types.h"
#include "Fonts.h"



namespace Eegeo
{
    namespace Fonts
    {
        class FontMaterialSetFactory : public IFontMaterialSetFactory, private Eegeo::NonCopyable
        {
        public:
            FontMaterialSetFactory(Rendering::Materials::ITextMaterialFactory& textMaterialFactory);
            
            FontMaterialSet* Create(const Fonts::FontInstance& fontInstance, const Fonts::FontMaterialSetProperties& properties);
        private:
            Rendering::Materials::ITextMaterialFactory& m_textMaterialFactory;
        };
    }
}