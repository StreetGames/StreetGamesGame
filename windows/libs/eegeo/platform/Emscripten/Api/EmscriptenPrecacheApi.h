#pragma once

#include "Types.h"

#include "EmscriptenApi.h"
#include "EmscriptenPrecacheOperation.h"
#include "PrecacheService.h"
#include "ICallback.h"

#include <map>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class EmscriptenPrecacheApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenPrecacheApi(const TMapId& mapId, Web::PrecacheService& precacheService);
                ~EmscriptenPrecacheApi();

                void OnUpdate();

                void BeginPrecacheOperation(
                    TOperationId operationId, 
                    const Eegeo::Space::LatLongAltitude& centre, 
                    double radius,
                    void (*completeCallback)(int),
                    void (*cancelCallback)(int));
                void CancelPrecacheOperation(TOperationId);

            private:
                void IssuePrecacheOperation(EmscriptenPrecacheOperation* pOperation);
                void ClearInFlightOperation();
                
                void HandlePrecacheCompleted();
                void HandlePrecacheCancelled();

                void NotifyPrecacheCompleted(EmscriptenPrecacheOperation* pOperation);
                void NotifyPrecacheCancelled(EmscriptenPrecacheOperation* pOperation);

                const TMapId m_mapId;

                EmscriptenPrecacheOperation* m_inFlightOperation;
                std::map<TOperationId, EmscriptenPrecacheOperation*> m_operations;

                Web::PrecacheService& m_precacheService;
                Helpers::TCallback0<EmscriptenPrecacheApi> m_precacheCompletedCallback;
                Helpers::TCallback0<EmscriptenPrecacheApi> m_precacheCancelledCallback;
            };
        }
    }
}