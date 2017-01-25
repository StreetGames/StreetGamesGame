#pragma once

#include "Types.h"

#include "EmscriptenApi.h"
#include "EmscriptenAnnotation.h"
#include "LatLongAltitude.h"
#include "RenderCamera.h"
#include "TerrainHeightProvider.h"
#include "Interiors.h"

#include <map>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class EmscriptenAnnotationsApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenAnnotationsApi(
                    const EmscriptenSpacesApi& spacesApi,
                    const Resources::Terrain::Heights::TerrainHeightProvider& terrainHeightProvider,
                    const Resources::Interiors::InteriorInteractionModel& interiorInteractionModel);
                    
                ~EmscriptenAnnotationsApi();

                void OnDraw();

                void CreateAnnotation(TAnnotationId annotationId, const Eegeo::Space::LatLong& position, double elevation);
                void MoveAnnotation(TAnnotationId annotationId, const Eegeo::Space::LatLong& position, double elevation);
                void RemoveAnnotation(TAnnotationId annotationId);
                EmscriptenAnnotation& GetAnnotation(TAnnotationId annotationId);

            private:
                void UpdateAllAnnotationScreenPositions();
                void UpdateAnnotationScreenPosition(EmscriptenAnnotation& annotation);
                void TryUpdateAltitudeOfAnnotation(EmscriptenAnnotation& annotation);

                const EmscriptenSpacesApi& m_spacesApi;
                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;
                const Resources::Interiors::InteriorInteractionModel& m_interiorInteractionModel;

                std::map<TAnnotationId, EmscriptenAnnotation*> m_annotations;
            };
        }
    }
}