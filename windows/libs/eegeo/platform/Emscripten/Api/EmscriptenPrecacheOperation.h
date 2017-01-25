#pragma once

#include "Types.h"
#include "LatLongAltitude.h"
#include "IStreamingVolume.h"

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            typedef int TOperationId;

            class EmscriptenPrecacheOperation
            {
            public:                
                EmscriptenPrecacheOperation(
                    const TOperationId& operationId, 
                    Streaming::IStreamingVolume* pStreamingVolume,
                    void (*completeCallback)(int),
                    void (*cancelCallback)(int) 
                );
                ~EmscriptenPrecacheOperation();

                const TOperationId& GetOperationId() const;
                Streaming::IStreamingVolume& GetStreamingVolume();                
                void  CallCompleteCallback() const ;
                void  CallCancelCallback() const ;

            private:

                TOperationId m_operationId;
                Streaming::IStreamingVolume* m_pStreamingVolume;
                void (*m_completeCallback)(int);
                void (*m_cancelCallback)(int);
            };
        }
    }
}