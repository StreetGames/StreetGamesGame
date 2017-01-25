// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once



#include "Types.h"
#include "Labels.h"
#include "Text.h"
#include "Fonts.h"

#include <string>

namespace Eegeo
{
    namespace Labels
    {
        class ILabelViewFactory
        {
        public:
            virtual ~ILabelViewFactory() {;}
            
            virtual LabelView* Create(const IAnchoredLabel& anchoredLabel, const std::string& styleName) = 0;
        };
        
        class LabelViewFactory : public ILabelViewFactory, private Eegeo::NonCopyable
        {
        public:
            LabelViewFactory(const ILabelStyleRepository& labelStyleRepository,
                             const ILabelAnchorFilterModel& labelHiddenFilterModel,
                             const std::string& defaultLabelStyleName);
            
            LabelView* Create(const IAnchoredLabel& anchoredLabel, const std::string& labelStyleName);
            
        private:
            const LabelStyle* GetLabelStyleOrDefault(const std::string& labelStyleName);
            const ILabelStyleRepository& m_labelStyleRepository;
            const ILabelAnchorFilterModel& m_labelHiddenFilterModel;
            const std::string m_defaultLabelStyleName;
        };
    }
}
