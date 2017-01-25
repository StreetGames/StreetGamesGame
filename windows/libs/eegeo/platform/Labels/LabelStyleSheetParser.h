// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "ILabelStyleSheetParser.h"
#include "Types.h"

#include "document.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        
        class LabelStyleSheetParser : public ILabelStyleSheetParser, private Eegeo::NonCopyable
        {
        public:
            LabelStyleSheetParser(const LabelTextStyleDto& defaultLabelTextStyle, const LabelStyleDto& defaultLabelStyle);
            
            bool TryParse(const std::string& labelStyleJson, LabelStyleSheetParserResult& out_result) const;
            
        private:
        
            bool ParseLabelTextStyles(const rapidjson::Value& labelTextStyleJsonArray, std::vector<LabelTextStyleDto>& results) const;
            bool ParseLabelStyles(const rapidjson::Value& labelStyleJsonArray, std::vector<LabelStyleDto>& results) const;
            bool ParseLabelStyleBindings(const rapidjson::Value& labelStyleBindingJsonArray, std::vector<LabelStyleBindingDto>& results) const;
            
            bool ParseLabelTextStyle(const rapidjson::Value& labelTextStyleJson, LabelTextStyleDto& result) const;
            bool ParseLabelStyle(const rapidjson::Value& labelStyleJson, LabelStyleDto& result) const;
            bool ParseLabelStyleBinding(const rapidjson::Value& labelStyleBindingJson, LabelStyleBindingDto& result) const;
            
            LabelTextStyleDto m_defaultLabelTextStyle;
            LabelStyleDto m_defaultLabelStyle;
            
            const std::vector<std::string> m_labelResourceEnumTokens;
            const std::vector<std::string> m_labelOrientationEnumTokens;
            const std::vector<std::string> m_labelDisplayEnumTokens;
            const std::vector<std::string> m_labelHorizontalAlignmentEnumTokens;
            const std::vector<std::string> m_labelVerticalAlignmentEnumTokens;
            const std::vector<std::string> m_labelStencilModeEnumTokens;
        };
    }
}