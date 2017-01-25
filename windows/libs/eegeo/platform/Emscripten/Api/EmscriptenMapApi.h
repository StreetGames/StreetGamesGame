#pragma once

#include "Types.h"

#include "EmscriptenApi.h"

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class EmscriptenMapApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenMapApi(
                    TMapId mapId,
                    EmscriptenIndoorsApi* indoorsApi,
                    EmscriptenSpacesApi* spacesApi,
                    EmscriptenThemesApi* themesApi,
                    EmscriptenAnnotationsApi* annotationsApi,
                    EmscriptenGeofenceApi* geofenceApi,
                    EmscriptenPrecacheApi* precacheApi,
                    EmscriptenCameraApi* cameraApi,
                    EmscriptenExpandFloorsApi* expandFloorsApi,
                    EmscriptenDebugTerminalApi* debugTerminalApi);

                ~EmscriptenMapApi();

                void OnUpdate(float deltaSeconds) const;
                void OnDraw(float deltaSeconds) const;

                void NotifyInitialized();
                void NotifyInitialStreamingCompleted();
                void NotifyThemesStreamingCompleted();

                bool Initialized() const;
                bool InitialStreamingCompleted() const;
                bool ThemesStreamingCompleted() const;

                void SetTopLevelCallbacks(void (*updateCallback)(float), void (*drawCallback)(float), void (*streamingCompletedCallback)(void));

                EmscriptenIndoorsApi& GetIndoorsApi();
                EmscriptenSpacesApi& GetSpacesApi();
                EmscriptenThemesApi& GetThemesApi();
                EmscriptenAnnotationsApi& GetAnnotationsApi();
                EmscriptenGeofenceApi& GetGeofenceApi();
                EmscriptenPrecacheApi& GetPrecacheApi();
                EmscriptenCameraApi& GetCameraApi();
                EmscriptenExpandFloorsApi& GetExpandFloorsApi();
                EmscriptenDebugTerminalApi& GetDebugTerminalApi();

            private:
                const TMapId m_mapId;
                
                bool m_initialized;
                bool m_initialStreamingCompleted;
                bool m_themesStreamingCompleted;

                void (*m_pUpdateCallback)(float);
                void (*m_pDrawCallback)(float);
                void (*m_pStreamingCompletedCallback)(void);

                EmscriptenIndoorsApi* m_pIndoorsApi;
                EmscriptenSpacesApi* m_pSpacesApi;
                EmscriptenThemesApi* m_pThemesApi;
                EmscriptenAnnotationsApi* m_pAnnotationsApi;
                EmscriptenGeofenceApi* m_pGeofenceApi;
                EmscriptenPrecacheApi* m_pPrecacheApi;
                EmscriptenCameraApi* m_pCameraApi;
                EmscriptenExpandFloorsApi* m_pExpandFloorsApi;
                EmscriptenDebugTerminalApi* m_pDebugTerminalApi;
            };
        }
    }
}