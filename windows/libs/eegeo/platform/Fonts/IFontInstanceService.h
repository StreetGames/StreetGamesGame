// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Fonts.h"
#include <string>


namespace Eegeo
{
    namespace Fonts
    {
        class IFontInstanceService
        {
        public:
            virtual ~IFontInstanceService() {;}
            
            virtual bool LoadSynchronous(const std::string& fontUrl, std::string& out_fontInstanceId) = 0;
            
            virtual void Release(const std::string& fontInstanceId) = 0;
            
            virtual bool IsLoaded(const std::string& fontInstanceId) const = 0;
            
            virtual const FontInstance& GetFontInstance(const std::string& fontInstanceId) const = 0;
        };
    }
}