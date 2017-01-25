// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Rendering.h"
#include "Modules.h"
#include "Streaming.h"
#include "Culling.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class BuildingPresentationModule : protected Eegeo::NonCopyable
                {
                public:
                    BuildingPresentationModule(Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& buildingSceneElementRepository,
                                               Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                               Culling::CullingVolumeVisibilityUpdater& cullingVolumeVisibilityUpdater);
                    
                    ~BuildingPresentationModule();
                    static BuildingPresentationModule* Create(BuildingModelModule& buildingModelModule,
                                                              Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                              Culling::CullingVolumeVisibilityUpdater& cullingVolumeVisibilityUpdater);
                    
                    Rendering::Filters::PackedRenderableFilter& GetBuildingRenderableFilter() const;
                    
                private:
                     Rendering::Filters::PackedRenderableFilter* m_pBuildingsPackedRenderableFilter;
                };
            }
        }
    }
}