// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "IFontInstanceService.h"

#include <map>

namespace Eegeo
{
    namespace Fonts
    {
        class FontInstanceService : public IFontInstanceService, private Eegeo::NonCopyable
        {
        public:
            FontInstanceService(FontLoader& fontLoader,
                                FontInstanceRepository& fontInstanceRepository,
                                IFontInstanceIdBuilder& fontInstanceIdBuilder);
            
            ~FontInstanceService();
            
            bool LoadSynchronous(const std::string& fontInstanceId, std::string& out_fontInstanceId);
            void Release(const std::string& fontInstanceId);
            
            bool IsLoaded(const std::string& fontInstanceId) const;
            const FontInstance& GetFontInstance(const std::string& fontInstanceId) const;
            
        private:
            void Unload(const std::string& fontInstanceId);
            FontLoader& m_fontLoader;
            FontInstanceRepository& m_fontInstanceRepository;
            IFontInstanceIdBuilder& m_fontInstanceIdBuilder;
        };
    }
}