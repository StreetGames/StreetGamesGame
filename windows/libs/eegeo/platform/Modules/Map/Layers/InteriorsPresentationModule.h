// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Modules.h"
#include "Interiors.h"
#include "Rendering.h"
#include "Streaming.h"
#include "InteriorsRenderableFilter.h"
#include "LandmarkToRenderableRepository.h"
#include "Lighting.h"
#include "Pins.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "Terrain.h"
#include "Camera.h"
#include "InteriorsConfiguration.h"
#include "Fonts.h"
#include "Labels.h"
#include "Culling.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class InteriorsPresentationModule
                {
                public:
                    ~InteriorsPresentationModule();
                    
                    static InteriorsPresentationModule* Create(InteriorsModelModule& interiorsModelModule,
                                                               BuildingModelModule& buildingModelModule,
                                                               BuildingPresentationModule& buildingPresentationModule,
                                                               Core::LightingModule& lightingModule,
                                                               Core::RenderingModule& renderingModule,
                                                               Core::FontsModule& fontsModule,
                                                               Eegeo::Labels::LabelsModule& labelsModule,
                                                               Helpers::ITextureFileLoader& textureFileLoader,
                                                               TerrainModelModule& terrainModelModule,
                                                               Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                                               Streaming::CameraFrustumStreamingVolume& streamingVolume,
                                                               Culling::CullingVolumeVisibilityUpdater& cullingVolumeVisibilityUpdater,
                                                               const Eegeo::Rendering::ScreenProperties& screenProperties,
                                                               Eegeo::Helpers::IFileIO& fileIO,
                                                               Map::Layers::PlaceNamesPresentationModule& placenamesPresentationModule,
                                                               Map::Layers::PlaceNamesModelModule& placeNamesModelModule,
                                                               const Resources::Interiors::InteriorsConfiguration& interiorsConfig,
                                                               bool enableInteriors,
                                                               bool interiorsAffectedByFlattening);
                    
                    static Resources::Interiors::InteriorsConfiguration DefaultConfig();
                    
                    Rendering::Filters::InteriorsRenderableFilter& GetInteriorsRenderableFilter() const;
                    
                    Resources::Interiors::InteriorsBackgroundRenderableFilter& GetInteriorsBackgroundRenderableFilter() const;
                    
                    Resources::Interiors::InteriorSelectionModel& GetInteriorSelectionModel() const;
                    
                    Resources::Interiors::InteriorInteractionModel& GetInteriorInteractionModel() const;
                    
                    Resources::Interiors::InteriorTransitionModel& GetInteriorTransitionModel() const;
                    
                    Resources::Interiors::IImmutableInteriorViewModel& GetInteriorViewModel() const;
                    
                    void Update(float dt, const Eegeo::Camera::RenderCamera& renderCamera);
                    
                    Resources::Interiors::Entities::IInteriorsLabelController& GetInteriorsLabelsController() const;
                    
                    const Resources::Interiors::InteriorsConfiguration& GetConfig() const;
                    
                    const Resources::Interiors::InteriorsHeightProvider& GetInteriorsHeightProvider() const;
                    
                private:
                    InteriorsPresentationModule(const Resources::Interiors::InteriorsConfiguration& interiorsConfig,
                                                Resources::Interiors::InteriorSelectionModel* pInteriorSelectionModel,
                                                Eegeo::Rendering::Shaders::ColorShader* pQuadShader,
                                                Resources::Interiors::InteriorsBackgroundMaterial* pInteriorsBackgroundMaterial,
                                                Resources::Interiors::InteriorsBackgroundRenderable* pInteriorsBackgroundRenderable,
                                                Resources::Interiors::InteriorsBackgroundViewModel* pInteriorsBackgroundViewModel,
                                                Resources::Interiors::InteriorsBackgroundRenderableFilter* pInteriorsBackgroundRenderableFilter,
                                                Rendering::Filters::InteriorsRenderableFilter* pInteriorsRenderableFilter,
                                                Resources::Interiors::InteriorFloorAnimator* pInteriorFloorAnimator,
                                                Resources::Interiors::InteriorInteractionModel* pInteriorInteractionModel,
                                                Resources::Interiors::InteriorTransitionModel* pInteriorTransitionModel,
                                                Resources::Interiors::InteriorInteractionModelAnimator* pInteriorInteractionModelAnimator,
                                                Resources::Interiors::InteriorController* pController,
                                                Resources::Interiors::InteriorViewModel* pViewModel,
                                                Resources::Interiors::InteriorLandmarkViewModel* pInteriorLandmarkViewModel,
                                                Fonts::IFontInstanceService& fontInstanceService,
                                                const Fonts::FontInstance* pLabelFont,
                                                Resources::Interiors::Entities::IInteriorsLabelController* pInteriorsLabelsController,
                                                Resources::Interiors::InteriorsHeightProvider* pInteriorsHeightProvicer,
                                                Resources::Interiors::InteriorLabelModel* pInteriorLabelModel,
                                                Resources::Interiors::InteriorLabelModelController* pInteriorLabelModelController);
                    
                    const Resources::Interiors::InteriorsConfiguration m_interiorsConfig;
                    
                    Resources::Interiors::InteriorSelectionModel* m_pInteriorSelectionModel;
                    
                    Eegeo::Rendering::Shaders::ColorShader* m_pQuadShader;
                    
                    Resources::Interiors::InteriorsBackgroundMaterial* m_pInteriorsBackgroundMaterial;
                    Resources::Interiors::InteriorsBackgroundRenderable* m_pInteriorsBackgroundRenderable;
                    
                    Resources::Interiors::InteriorsBackgroundViewModel* m_pInteriorsBackgroundViewModel;
                    Resources::Interiors::InteriorsBackgroundRenderableFilter* m_pInteriorsBackgroundRenderableFilter;
                    
                    Rendering::Filters::InteriorsRenderableFilter* m_pInteriorsRenderableFilter;
                    
                    Resources::Interiors::InteriorFloorAnimator* m_pInteriorFloorAnimator;
                    Resources::Interiors::InteriorInteractionModel* m_pInteriorInteractionModel;
                    Resources::Interiors::InteriorTransitionModel* m_pInteriorTransitionModel;
                    Resources::Interiors::InteriorInteractionModelAnimator* m_pInteriorInteractionModelAnimator;
                    Resources::Interiors::InteriorController* m_pController;
                    Resources::Interiors::InteriorViewModel* m_pViewModel;
                    Resources::Interiors::InteriorLandmarkViewModel* m_pInteriorLandmarkViewModel;
                    
                    Fonts::IFontInstanceService& m_fontInstanceService;
                    const Fonts::FontInstance* m_pLabelFont;
                    Resources::Interiors::Entities::IInteriorsLabelController* m_pInteriorsLabelsController;
                    Resources::Interiors::InteriorsHeightProvider* m_pInteriorsHeightProvider;
                    Resources::Interiors::InteriorLabelModel* m_pInteriorLabelModel;
                    Resources::Interiors::InteriorLabelModelController* m_pInteriorLabelModelController;
                };
            }
        }
    }
}