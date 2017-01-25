// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include "Fonts.h"
#include "Roads.h"
#include "Rendering.h"
#include "Location.h"
#include "Camera.h"
#include "Streaming.h"
#include "Modules.h"
#include "VectorMathDecl.h"
#include "TextRenderableConfiguration.h"
#include "Culling.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class TransportPresentationModule : Eegeo::NonCopyable
                {
                public:
                    TransportPresentationModule(const Fonts::FontInstance& environmentFont,
                                                const Rendering::Shaders::TextShaderSet& textShaderSet,
                                                const Rendering::Renderables::TextRenderableConfiguration& textAppearance,
                                                Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                                Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& roadsSceneElementRepository,
                                                Rendering::Scene::SceneElementRepository<Rendering::Renderables::TextRenderable>& roadNamesSceneElementRepository,
                                                Culling::CullingVolumeVisibilityUpdater& cullingVolumeVisibilityUpdater,
                                                Rendering::EnvironmentFlatteningService& environmentFlatteningService);
                    
                    ~TransportPresentationModule();
                    
                    static TransportPresentationModule* Create(Core::FontsModule& fontsModule,
                                                               Core::RenderingModule& renderingModule,
                                                               TransportModelModule& transportModelModule,
                                                               Culling::CullingVolumeVisibilityUpdater& cullingVolumeVisibilityUpdater,
                                                               Rendering::EnvironmentFlatteningService& environmentFlatteningService);
                    
                    Fonts::FontMaterialSet& GetRoadNamesFontMaterialSet() const;
                    Rendering::Renderables::TextRenderableConfiguration GetTextAppearance() const;
                    Resources::Roads::RoadNamesFadeController& GetRoadNamesFadeController() const;
                    Rendering::Filters::PackedRenderableFilter& GetRoadsRenderableFilter() const;
                    Resources::Roads::RoadNamesRenderableFilter& GetRoadNamesRenderableFilter() const;

                    void Update(float dt, const double& cameraAltitude, const dv3& ecefInterestPoint);
                    
                private:
                    Fonts::FontMaterialSet* m_pRoadNamesFontMaterialSet;
                    const Rendering::Renderables::TextRenderableConfiguration m_textAppearance;
                    Rendering::Materials::ITextMaterialFactory* m_pTextMaterialFactory;
                    Resources::Roads::RoadNamesFadeController* m_pRoadNamesFadeController;
                    Rendering::Filters::PackedRenderableFilter* m_pRoadsPackedRenderableFilter;
                    Resources::Roads::RoadNamesRenderableFilter* m_pRoadNamesRenderableFilter;
                };
            }
        }
    }
}