// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Labels.h"
#include "ILabelStyleFactory.h"
#include "Fonts.h"
#include "Types.h"


namespace Eegeo
{
    namespace Labels
    {
        class LabelStyleFactory : public ILabelStyleFactory, private Eegeo::NonCopyable
        {
        public:
            LabelStyleFactory(const ILabelTextStyleRepository& labelTextStyleRepository);
            
            LabelStyle* Create(const LabelStyleDto& labelStyleDto);
        private:
            const ILabelTextStyleRepository& m_labelTextStyleRepository;
        };
    }
}