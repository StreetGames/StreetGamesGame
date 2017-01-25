#pragma once

#include "Types.h"

#include "EmscriptenApi.h"
#include "CityThemesModule.h"
#include "CityThemes.h"
#include "ICityThemeChangedObserver.h"

#include <string>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class EmscriptenThemesApi: public Resources::CityThemes::ICityThemeChangedObserver, protected Eegeo::NonCopyable
            {
            public:
                EmscriptenThemesApi(const TMapId& mapId, const Modules::Map::CityThemesModule& cityThemesModule);
                ~EmscriptenThemesApi();

                void SetTheme(const std::string& themeNameContains) const;
                void SetState(const std::string& themeStateName, float transitionSpeed) const;
                void SetStreamingCompleteCallback(void (*completeCallback)(void));

                void OnThemeRequested(const Resources::CityThemes::CityThemeData& newTheme);
                void OnThemeChanged(const Resources::CityThemes::CityThemeData& newTheme);

            private:
                TMapId m_mapId;
                Resources::CityThemes::ICityThemesService& m_cityThemesService;
                Resources::CityThemes::ICityThemesUpdater& m_cityThemesUpdater;

                bool m_themesStreamingCompleted;                
                void (*m_streamingCompleteCallback)(void);
            };
        }
    }
}