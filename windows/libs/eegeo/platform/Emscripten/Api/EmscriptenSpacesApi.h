#pragma once

#include "Types.h"

#include "LatLongAltitude.h"
#include "RenderCamera.h"
#include "IRayPicker.h"
#include "TerrainRayPicker.h"
#include "TerrainModelModule.h"
#include "TerrainHeightProvider.h"
#include "Interiors.h"
#include "Modules.h"


namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class EmscriptenSpacesApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenSpacesApi(
                    const Eegeo::Camera::RenderCamera& initialRenderCamera,
                    const Modules::Map::Layers::TerrainModelModule& terrainModelModule,
                    const Eegeo::Modules::Map::Layers::InteriorsPresentationModule& interiorsPresentationModule);

                ~EmscriptenSpacesApi();

                Eegeo::v3 WorldToScreen(const Eegeo::Space::LatLongAltitude& point) const;
                float GetAltitudeAtLatLng(const Eegeo::Space::LatLong& point) const;
                bool GetUpdatedAltitudeAtPoint(const Eegeo::dv3& point, float previousHeight, int previousLevel, float& newHeight, int& newLevel) const;

                bool TryGetScreenToTerrainPoint(const Eegeo::v2& point, Space::LatLongAltitude& out_worldPoint) const;
                bool TryGetScreenToIndoorPoint(const Eegeo::v2& point, Space::LatLongAltitude& out_worldPoint) const;

                void UpdateRenderCamera(const Eegeo::Camera::RenderCamera& renderCamera);

            private:
                bool PerformTerrainRayPick(
                    const Eegeo::dv3& rayOrigin,
                    Eegeo::dv3& rayDirection,
                    Eegeo::dv3& out_rayIntersectionPoint) const;

                bool PerformIndoorRayPick(
                    const Eegeo::dv3& rayOrigin,
                    Eegeo::dv3& rayDirection,
                    Eegeo::dv3& out_rayIntersectionPoint) const;

                const Resources::Terrain::Heights::TerrainHeightProvider& m_terrainHeightProvider;

                Eegeo::Camera::RenderCamera m_renderCamera;
                Collision::IRayPicker* m_pRayPicker;
                Resources::Interiors::InteriorTransitionModel& m_interiorTransitionModel;
                Resources::Interiors::InteriorInteractionModel& m_interiorInteractionModel;
            };
        }
    }
}