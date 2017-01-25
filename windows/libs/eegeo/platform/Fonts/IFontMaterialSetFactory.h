// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fonts.h"
#include "Rendering.h"


namespace Eegeo
{
    namespace Fonts
    {
        class IFontMaterialSetFactory
        {
        public:
            virtual ~IFontMaterialSetFactory() {}
            
            virtual FontMaterialSet* Create(const Fonts::FontInstance& fontInstance, const Fonts::FontMaterialSetProperties& properties) = 0;
        };
    }
}