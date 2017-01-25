// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "Labels.h"


namespace Eegeo
{
    namespace Labels
    {
        class ILabelStyleSheetBuilder
        {
        public:
            virtual ~ILabelStyleSheetBuilder() {}
            
            virtual void CreateAndRegisterStyles(const LabelStyleSheetParserResult& styleSheetDto) = 0;
        };
    }
}