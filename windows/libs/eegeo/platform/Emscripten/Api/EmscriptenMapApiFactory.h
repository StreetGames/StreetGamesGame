#pragma once

#include "Types.h"

#include "EmscriptenApi.h"
#include "Interiors.h"
#include "Modules.h"
#include "PrecacheService.h"
#include "RenderCamera.h"
#include "GpsGlobeCameraController.h"
#include "TerrainModelModule.h"
#include "CommandBuffer.h"

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class EmscriptenMapApiFactory
            {
            public:

                static EmscriptenMapApi* CreateMapApi(
                    int mapId,
                    const Modules::Map::CityThemesModule& cityThemesModule,
                    const Modules::Map::Layers::InteriorsPresentationModule& interiorsPresentationModule,
                    Resources::Interiors::Markers::InteriorMarkerModelRepository& interiorMarkerModelRepository,
                    Eegeo::Resources::Interiors::InteriorsEntityIdHighlightController& interiorsEntityIdHighlightController,
                    Modules::Data::GeofenceModule& geofenceModule,
                    Web::PrecacheService& precacheService,
                    const Eegeo::Camera::RenderCamera& initialRenderCamera,
                    Camera::GlobeCamera::GpsGlobeCameraController& gpsGlobeCameraController,
                    Resources::Interiors::InteriorsCameraController& interiorsCameraController,
                    const Modules::Map::Layers::TerrainModelModule& terrainModelModule,
                    Eegeo::Debug::Commands::CommandBuffer& commandBuffer
                    );
            };
        }
    }
}