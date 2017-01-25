// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Terrain.h"
#include "Rendering.h"
#include "Streaming.h"
#include "Modules.h"
#include "Culling.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class TerrainPresentationModule : protected Eegeo::NonCopyable
                {
                public:
                    TerrainPresentationModule(Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& lcmTerrainSceneElementRepository,
                                              Rendering::Scene::SceneElementRepository<Rendering::Renderables::WorldMeshRenderable>& rasterTerrainSceneElementRepository,
                                              Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                              Culling::CullingVolumeVisibilityUpdater& cullingVolumeVisibilityUpdater);
                    
                    ~TerrainPresentationModule();
                    
                    static TerrainPresentationModule* Create(TerrainModelModule& terrainModelModule,
                                                             Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                             Culling::CullingVolumeVisibilityUpdater& cullingVolumeVisibilityUpdater);
                    
                    Rendering::Filters::PackedRenderableFilter& GetLcmTerrainRenderableFilter() const;
                    Rendering::Filters::DefaultRenderableFilter& GetRasterTerrainRenderableFilter() const;
                private:
                    Rendering::Filters::PackedRenderableFilter* m_pLcmPackedRenderableFilter;
                    Rendering::Filters::DefaultRenderableFilter* m_pRasterTerrainRenderableFilter;
                };
            }
        }
    }
}