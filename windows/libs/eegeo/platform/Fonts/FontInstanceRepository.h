// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include <map>
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Fonts
    {
        class FontInstanceRepository : Eegeo::NonCopyable
        {
        public:
            FontInstanceRepository();
            
            ~FontInstanceRepository();
            
            bool Contains(const std::string& key) const;
            FontInstance* Get(const std::string& key) const;
            
            
            void Add(const std::string& key, FontInstance* pFontInstance);
            void Remove(const std::string& key);
            
            int GetReferenceCount(const std::string& key) const;
            void IncrementReferenceCount(const std::string& key);
            void DecrementReferenceCount(const std::string& key);
            
            std::vector<std::string> AllKeys() const;
            
        private:
            typedef std::pair<int, FontInstance*> RefCountedFontInstance;
            typedef std::map<std::string, RefCountedFontInstance> TStore;
            TStore m_store;
        };
    }
}