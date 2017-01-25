// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include <string>

#include "Types.h"
#include "Roads.h"
#include "Fonts.h"
#include "TextMeshes.h"
#include "CoverageTrees.h"
#include "Helpers.h"
#include "Rendering.h"
#include "Navigation.h"
#include "Modules.h"
#include "Collision.h"
#include "Labels.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class TransportStreamingModule : protected Eegeo::NonCopyable
                {
                public:
                    TransportStreamingModule(
                                             Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                             Rendering::MeshFactories::TextMeshFactory& textMeshFactory,
                                             Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                             Rendering::IMaterialProvider& materialProvider,
                                             Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& roadSceneElementRepository,
                                             Rendering::Scene::SceneElementRepository<Rendering::Renderables::TextRenderable>& roadNameSceneElementRepository,
                                             Rendering::Scene::SceneElementRepository<Rendering::Renderables::PackedRenderable>& shadowSceneElementRepository,
                                             Resources::Roads::Navigation::NavigationGraphRepository& roadNavGraphRepository,
                                             Resources::Roads::Navigation::NavigationGraphRepository& railNavGraphRepository,
                                             Resources::Roads::Navigation::NavigationGraphRepository& tramNavGraphRepository,
                                             Collision::CollisionMeshResourceRepository& roadsCollisionMeshResourceRepository,
                                             Collision::CollisionMeshResourceRepository& railCollisionMeshResourceRepository,
                                             Collision::CollisionMeshResourceRepository& tramlinesCollisionMeshResourceRepository,
                                             Labels::ILabelCellResourceObserver& labelCellResourceObserver,
                                             Labels::ILabelAnchorCategoryRepository& labelAnchorCategoryRepository,
                                             Labels::ILabelLayerService& labelLayerService,
                                             const Fonts::FontInstance& roadNameFont,
                                             const Fonts::FontMaterialSet& roadNameFontMaterialSet,
                                             const Rendering::Renderables::TextRenderableConfiguration& textAppearance,
                                             const bool generateCollision,
                                             const bool buildLabels);
                    
                    ~TransportStreamingModule();
                    
                    static TransportStreamingModule* Create(Core::RenderingModule& renderingModule,
                                                            EnvironmentMaterialModule& environmentMaterialModule,
                                                            TransportModelModule& transportModelModule,
                                                            TransportPresentationModule& transportPresentationModule,
                                                            Core::FontsModule& fontsModule,
                                                            Labels::LabelsModule& labelsModule,
                                                            ShadowModelModule& shadowModelModule,
                                                            Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                                            const bool generateCollisionForAllResources,
                                                            const bool buildLabels);
                
                    Resources::Roads::RoadStreaming& GetRoadStream() const;
                    Resources::Roads::ChunkedRoadBuilder& GetRoadBuilder() const;
                    
                private:
                    Resources::Roads::RoadStreaming* m_pRoadStream;
                    Resources::Roads::RoadNameTransformBuilder* m_pRoadNameTransformBuilder;
                    Resources::Roads::RoadNameGeometryBuilder* m_pRoadNameGeometryBuilder;
                    Resources::Roads::ChunkedRoadBuilder* m_pRoadBuilder;
                    TextMeshes::PreTransformedTextMeshBuilder* m_pRoadNamesTextMeshBuilder;
                    Resources::Roads::IRoadLabelAnchorCategoryMapper* m_pRoadLabelAnchorCategoryMapper;
                    Resources::Roads::IRoadNameClassificationPatcher* m_pRoadNameClassificationPatcher;
                    Resources::Roads::IRoadLabelBuilder* m_pRoadLabelBuilder;
                    
                    Resources::Roads::Navigation::NavigationGraphBuilder* m_pRoadNavGraphBuilder;
                    Resources::Roads::Navigation::NavigationGraphBuilder* m_pRailNavGraphBuilder;
                    Resources::Roads::Navigation::NavigationGraphBuilder* m_pTramNavGraphBuilder;
                };
            }
        }
    }
}