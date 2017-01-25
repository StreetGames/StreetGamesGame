// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include <string>

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            struct FontsModuleConfiguration
            {
                FontsModuleConfiguration()
                : UseNullSdfShader(false)
                {};
                
                std::string EnvironmentFontFilename;
                bool UseNullSdfShader;
            };
        }
    }
}