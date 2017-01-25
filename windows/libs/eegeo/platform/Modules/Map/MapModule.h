// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>
#include <vector>

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Location.h"
#include "Camera.h"
#include "Streaming.h"
#include "Web.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "IEegeoErrorHandler.h"
#include "NativeUIFactories.h"
#include "Tasks.h"
#include "VectorMathDecl.h"
#include "IJpegLoader.h"
#include "DebugRendering.h"
#include "Profiler.h"
#include "Collision.h"
#include "Interiors.h"
#include "RenderingModule.h"
#include "FontsModule.h"
#include "LightingModule.h"
#include "ITextureFileLoader.h"
#include "TerrainModelModule.h"
#include "ScreenProperties.h"
#include "IConnectivityService.h"
#include "Config.h"
#include "CoverageTrees.h"
#include "PlatformConfig.h"
#include "Labels.h"
#include "Text.h"
#include "MapLayers.h"
#include "Culling.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            class MapModule : protected Eegeo::NonCopyable
            {
            public:
                MapModule(
                          Web::IWebLoadRequestFactory& webLoadRequestFactory,
                          Web::IConnectivityService& connectivityService,
                          Helpers::IHttpCache& httpCache,
                          Helpers::ITextureFileLoader& textureLoader,
                          Helpers::IFileIO& fileIO,
                          
                          Core::RenderingModule& renderingModule,
                          Core::FontsModule& fontsModule,
                          Core::LightingModule& lightingModule,
                          Core::AsyncLoadersModule& asyncLoadersModule,
                          Core::SceneModelsModule& sceneModelsModule,
                          Core::DebugRenderingModule& debugRenderingModule,
                          Text::ScreenTextRenderingModule& screenTextRenderingModule,
                          
                          Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader,
                          UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                          IEegeoErrorHandler* pErrorHandler,
                          Concurrency::Tasks::IWorkPool& workPool,
                          const Rendering::ScreenProperties& screenProperties,
                          const size_t resourceNodeCacheEntries,
                          const std::vector<double>& altitudes,
                          const Config::PlatformConfig& platformConfig);

                ~MapModule();
                
                static MapModule* Create(
                        Modules::IPlatformAbstractionModule& platformAbstractionModule,
                        Modules::Core::CoreModule& coreModule,
                        Helpers::Jpeg::IJpegLoader& jpegLoader,
                        UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                        IEegeoErrorHandler* pErrorHandler,
                        Concurrency::Tasks::IWorkPool& workPool,
                        const Config::PlatformConfig& platformConfig,
                        const Rendering::ScreenProperties& screenProperties,
                        const size_t resourceNodeCacheEntries,
                        const std::vector<double>& altitudes);

                
                bool IsRunning() const { return m_running; }
                void Start();
                void EarlyUpdate(float dt);
                void Update(float dt,
                            const Camera::RenderCamera& renderCamera,
                            const dv3& ecefInterestPoint,
                            Streaming::IStreamingVolume& streamingVolume,
                            Eegeo::Debug::Profile::Profiler& profiler);
                
                Rendering::EnvironmentFlatteningService& GetEnvironmentFlatteningService() const;
                Streaming::CameraFrustumStreamingVolume& GetStreamingVolume() const;
                Streaming::ResourceCeilingProvider& GetResourceCeilingProvider() const;
                Eegeo::Collision::AggregateCollisionBvhProvider& GetAggregateCollisionBvhProvider() const;
                
                WeatherModule& GetWeatherModule() const;
                CityThemesModule& GetCityThemesModule() const;
                CoverageTreeModule& GetCoverageTreeModule() const;
                Layers::PlaceNamesModelModule& GetPlaceNamesModelModule() const;
                Layers::PlaceNamesPresentationModule& GetPlaceNamesPresentationModule() const;
                Layers::PlaceNamesStreamingModule& GetPlaceNamesStreamingModule() const;
                EnvironmentMaterialModule& GetEnvironmentMaterialModule() const;
                StreamingModule& GetStreamingModule() const;
                Layers::BuildingModelModule& GetBuildingModelModule() const;
                Layers::BuildingStreamingModule& GetBuildingStreamingModule() const;
                Layers::BuildingPresentationModule& GetBuildingPresentationModule() const;
                Layers::TransportStreamingModule& GetTransportStreamingModule() const;
                Layers::TransportModelModule& GetTransportModelModule() const;
                Layers::TransportPresentationModule& GetTransportPresentationModule() const;
                Layers::TerrainStreamingModule& GetTerrainStreamingModule() const;
                Layers::TerrainModelModule& GetTerrainModelModule() const;
                Layers::TerrainPresentationModule& GetTerrainPresentationModule() const;
                Layers::ShadowModelModule& GetShadowModelModule() const;
                Layers::ShadowPresentationModule& GetShadowPresentationModule() const;
                
                Layers::InteriorsModelModule& GetInteriorsModelModule() const;
                Layers::InteriorsStreamingModule& GetInteriorsStreamingModule() const;
                Layers::InteriorsMaterialsModule& GetInteriorsMaterialsModule() const;
                Layers::InteriorsPresentationModule& GetInteriorsPresentationModule() const;
                Labels::LabelsModule& GetLabelsModule() const;
                
            private:
                
                WeatherModule* m_pWeatherModule;
                EnvironmentMaterialModule* m_pEnvironmentMaterialModule;
                CityThemesModule* m_pCityThemesModule;
                Labels::LabelsModule* m_pLabelsModule;
                
                StreamingModule* m_pStreamingModule;
                Streaming::CoverageTrees::ICoverageTreeManifestLoader* m_pCoverageTreeManifestLoader;
                CoverageTreeModule* m_pCoverageTreeModule;
                Culling::CullingVolumeVisibilityUpdater* m_pCullingVolumeVisibilityUpdater;

                Layers::TransportStreamingModule* m_pTransportStreamingModule;
                Layers::TransportModelModule* m_pTransportModelModule;
                Layers::TransportPresentationModule* m_pTransportPresentationModule;

                Layers::PlaceNamesStreamingModule* m_pPlaceNamesStreamingModule;
                Layers::PlaceNamesPresentationModule* m_pPlaceNamesPresentationModule;
                Layers::PlaceNamesModelModule* m_pPlaceNamesModelModule;

                Layers::BuildingModelModule* m_pBuildingModelModule;
                Layers::BuildingStreamingModule* m_pBuildingStreamingModule;
                Layers::BuildingPresentationModule* m_pBuildingPresentationModule;
                
                Layers::TerrainStreamingModule* m_pTerrainStreamingModule;
                Layers::TerrainModelModule* m_pTerrainModelModule;
                Layers::TerrainPresentationModule* m_pTerrainPresentationModule;
                
                Layers::InteriorsModelModule* m_pInteriorsModelModule;
                Layers::InteriorsPresentationModule* m_pInteriorsPresentationModule;
                Layers::InteriorsStreamingModule* m_pInteriorsStreamingModule;
                Layers::InteriorsMaterialsModule* m_pInteriorsMaterialsModule;
                
                Layers::ShadowModelModule* m_pShadowModelModule;
                Layers::ShadowPresentationModule* m_pShadowPresentationModule;

                
                Rendering::MeshFactories::PackedDiffuseReadMeshFactory* m_pPackedDiffuseReadMeshFactory;
                Rendering::MeshFactories::LcmReadMeshFactory* m_pLcmReadMeshFactory;
                
                Streaming::CameraFrustumStreamingVolume *m_pStreamingVolume;
                Streaming::ResourceCeilingProvider* m_pResourceCeilingProvider;
                Rendering::EnvironmentFlatteningService* m_pEnvironmentFlatteningService;
                
                Eegeo::Collision::AggregateCollisionBvhProvider* m_pAggregateCollisionBvhProvider;
                
                MapLayers::MapLayersModule* m_pMapLayersModule;
                
                Rendering::RenderableFilters& m_renderableFilters;
                
                bool m_running;
                
                void RegisterRenderableFilters(Rendering::RenderableFilters& renderableFilters) const;
                void UnregisterRenderableFilters(Rendering::RenderableFilters& renderableFilters) const;
                void InitialiseReadMeshFactories(Core::RenderingModule& renderingModule);
                void TeardownReadMeshFactories();
                
                void InitialiseLayerModelModules();
                void TeardownLayerModelModules();
                
                void InitialiseLayerPresentationModules(Core::RenderingModule& renderingModule,
                                                        Core::FontsModule& fontsModule,
                                                        Labels::LabelsModule& labelsModule,
                                                        Core::LightingModule& lightingModule,
                                                        Helpers::ITextureFileLoader& textureFileLoader,
                                                        Helpers::IFileIO& fileIO,
                                                        Layers::TerrainModelModule& terrainModelModule,
                                                        const Rendering::ScreenProperties& screenProperties,
                                                        const bool enableInteriors,
                                                        const bool interiorsAffectedByFlattening,
                                                        const Resources::Interiors::InteriorsConfiguration& interiorsConfig);
                
                void TeardownLayerPresentationModules();
                
                void InitialiseLayerStreamingModules(Core::RenderingModule& renderingModule,
                                                     Core::FontsModule& fontsModule,
                                                     Labels::LabelsModule& labelsModule,
                                                     Core::AsyncLoadersModule& asyncLoadersModule,
                                                     CityThemesModule& cityThemesModule,
                                                     Core::LightingModule& lightingModule,
                                                     Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                                     Web::IConnectivityService& connectivityService,
                                                     UI::NativeAlerts::IAlertBoxFactory& alertBoxFactory,
                                                     IEegeoErrorHandler* pErrorHandler,
                                                     Helpers::ITextureFileLoader& textureLoader,
                                                     Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader,
                                                     Helpers::IFileIO& fileIO,
                                                     const Rendering::ScreenProperties& screenProperties,
                                                     const Eegeo::Config::PlatformConfig& platformConfig);
                
                void TeardownLayerStreamingModules();
                
            };
        }
    }
}



