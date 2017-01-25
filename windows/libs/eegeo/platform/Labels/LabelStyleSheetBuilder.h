// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "ILabelStyleSheetBuilder.h"
#include "Types.h"

#include <string>

namespace Eegeo
{
    namespace Labels
    {
        class LabelStyleSheetBuilder : public ILabelStyleSheetBuilder, private Eegeo::NonCopyable
        {
        public:
            LabelStyleSheetBuilder(ILabelTextStyleFactory& labelTextStyleFactory,
                                   ILabelTextStyleRepository& labelTextStyleRepository,
                                   ILabelStyleFactory& labelStyleFactory,
                                   ILabelStyleRepository& labelStyleRepository,
                                   ILabelStyleBindingRepository& labelStyleBindingRepository);
            
            void CreateAndRegisterStyles(const LabelStyleSheetParserResult& styleSheetDto);
            
        private:
            void CreateAndAddTextStyle(const LabelTextStyleDto& labelTextStyleDto);
            void CreateAndAddLabelStyle(const LabelStyleDto& labelStyleDto);
            void CreateAndAddStyleBinding(const LabelStyleBindingDto& labelStyleBindingDto);
            
            ILabelTextStyleFactory& m_labelTextStyleFactory;
            ILabelTextStyleRepository& m_labelTextStyleRepository;
            ILabelStyleFactory& m_labelStyleFactory;
            ILabelStyleRepository& m_labelStyleRepository;
            ILabelStyleBindingRepository& m_labelStyleBindingRepository;
        };
    }
}