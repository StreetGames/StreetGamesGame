// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "Types.h"

#include <string>


namespace Eegeo
{
    namespace Labels
    {
    
        namespace LabelResource
        {
            enum Type
            {
                Roads,
                PlaceNames,
                Interiors
            };
        };
        
        
        class LabelResourceFontBinding : private Eegeo::NonCopyable
        {
        public:
            static inline LabelResourceFontBinding* Create(LabelResource::Type labelResourceType, const std::string& fontName);

            LabelResource::Type GetLabelResourceType() const { return m_labelResourceType; }

            const std::string& GetFontName() const { return m_fontName; }
            
        private:
            LabelResourceFontBinding(LabelResource::Type labelResourceType, const std::string& fontName)
            : m_labelResourceType(labelResourceType)
            , m_fontName(fontName)
            {}
            
            LabelResource::Type m_labelResourceType;
            std::string m_fontName;
        };
        
        inline LabelResourceFontBinding* LabelResourceFontBinding::Create(LabelResource::Type labelResourceType, const std::string& fontName)
        {
            return Eegeo_NEW(LabelResourceFontBinding)(labelResourceType, fontName);
        }
        
    }
}

