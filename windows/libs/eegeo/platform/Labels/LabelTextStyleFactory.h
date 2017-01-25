// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Labels.h"
#include "ILabelTextStyleFactory.h"
#include "Fonts.h"
#include "Types.h"

#include <string>

namespace Eegeo
{
    namespace Labels
    {
        class LabelTextStyleFactory : public ILabelTextStyleFactory, private Eegeo::NonCopyable
        {
        public:
            LabelTextStyleFactory(ILabelResourceFontBindingRepository& labelResourceFontBindingRepository,
                                  Fonts::IFontInstanceService& fontInstanceService,
                                  float sizeScaleForProjection,
                                  float sizeScaleForPixelDensity);
            
            LabelTextStyle* Create(const LabelTextStyleDto& LabelTextStyleDto);
        private:
            const Fonts::FontInstance* GetFontInstance(const std::string& fontName);
            
            ILabelResourceFontBindingRepository& m_labelResourceFontBindingRepository;
            Fonts::IFontInstanceService& m_fontInstanceService;
            const float m_sizeScaleForProjection;
            const float m_sizeScaleForPixelDensity;
        };
    }
}