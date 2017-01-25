// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "InteriorsMaterials.h"
#include "Modules.h"
#include "AsyncTexturing.h"
#include "Helpers.h"
#include "Interiors.h"
#include "Rendering.h"
#include "CityThemes.h"
#include "AsyncTexturing.h"
#include "Collision.h"
#include "IdTypes.h"
#include "Lighting.h"
#include "Helpers.h"
#include "Types.h"
#include "Web.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class InteriorsMaterialsModule : private Eegeo::NonCopyable
                {
                public:
                    InteriorsMaterialsModule(Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                             Rendering::GlBufferPool& glBufferPool,
                                             Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                             Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                             Rendering::AsyncTexturing::IAsyncTextureRequestor& remoteTextureLoader,
                                             Rendering::AsyncTexturing::IAsyncCubeTextureRequestor& remoteCubeTextureLoader,
                                             Rendering::AsyncTexturing::LocalAsyncTextureLoader& localTextureLoader,
                                             Resources::Interiors::InteriorsModelRepository& interiorsModelRepository,
                                             Resources::Interiors::Entities::InteriorsEntitiesRepository& interiorsEntitiesRepository,
                                             Resources::Interiors::Markers::InteriorMarkerModelRepository& interiorMarkerModelRepository,
                                             Collision::CollisionMeshResourceRepository& collisionMeshResourceRepository,
                                             Collision::CollisionMeshResourceRepository& highlightCollisionMeshResourceRepository,
                                             Resources::Interiors::InteriorsCellResourceObserver& interiorsCellResourceObserver,
                                             Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                             Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                             const Lighting::GlobalLighting& globalLighting,
                                             const bool interiorsAffectedByFlattening,
                                             Resources::CityThemes::ICityThemesService& cityThemeService,
                                             Eegeo::Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                             Eegeo::Helpers::IFileIO& fileIO);
                    
                    ~InteriorsMaterialsModule();
                    
                    static InteriorsMaterialsModule* Create(Modules::Core::RenderingModule& renderingModule,
                                                            Modules::Map::Layers::InteriorsModelModule& interiorsModelModule,
                                                            Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                                            Modules::Core::LightingModule& lightingModule,
                                                            Modules::Core::AsyncLoadersModule& asyncLoadersModule,
                                                            CityThemesModule& cityThemesModule,
                                                            Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                                            Eegeo::Helpers::IFileIO& fileIO,
                                                            const bool interiorsAffectedByFlattening);
                    
                    Resources::Interiors::IInteriorsMaterialService& GetInteriorsMaterialService() const;
                    
                    Resources::Interiors::IInteriorsMaterialAssignmentObserver& GetInteriorsMaterialAssignmentObserver() const;
                    
                    Resources::Interiors::Materials::IInteriorsMaterialDtoRepository& GetInteriorsMaterialDtoRepository() const;
                    
                    Resources::Interiors::InteriorsStencilMirrorClearRenderableFactory& GetInteriorsStencilMirrorClearRenderableFactory() const;
                    
                    Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsDiffuseTexturedMaterialFactory() const;
                    
                    Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsDiffuseTranslucentMaterialFactory() const;
                    
                    Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsDiffuseSpecularMaterialFactory() const;
                    
                    Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsCubeMappedMaterialFactory() const;
                    
                    Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsChromeMaterialFactory() const;
                    
                    Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsReflectionMaterialFactory() const;
                    
                    Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsStencilMirrorMaterialFactory() const;
                    
                    Resources::Interiors::IInteriorsTextureResourceService& GetInteriorsTextureResourceService() const;
                    
                    Resources::Interiors::IInteriorsMaterialPrioritizedFactory& GetInteriorsAggregateMaterialFactory() const;
                    
                    Resources::Interiors::Materials::IInteriorRenderablesRepository& GetInteriorRenderablesRepository() const;
                    
                private:
                    
                    bool TryGetLocalMaterialsJson(Eegeo::Helpers::IFileIO& fileIO,
                                                  std::string& materialsJson);
                    
                    void AddLocalMaterials(const std::string& materialsJson,
                                           Eegeo::Resources::Interiors::IInteriorsTextureResourceService& interiorsTextureResourceService,
                                           Eegeo::Resources::Interiors::Materials::IInteriorsMaterialDtoRepository& interiorsMaterialDtoRepository);
                    
                    Rendering::IMaterialRepository& GetInteriorsMaterialRepository() const;
                    
                    const Resources::Interiors::InteriorsShader& GetInteriorsShader() const;
                    
                    const Resources::Interiors::InteriorsDiffuseTexturedShader& GetInteriorsDiffuseTexturedShader() const;
                    
                    const Resources::Interiors::InteriorsDiffuseSpecularShader& GetInteriorsDiffuseSpecularShader() const;
                    
                    const Resources::Interiors::InteriorsCubeMappedShader& GetInteriorsCubeMappedShader() const;
                    
                    const Resources::Interiors::InteriorsChromeShader& GetInteriorsChromeShader() const;
                    
                    Resources::Interiors::IInteriorsMaterialFactory& GetInteriorsMaterialFactory() const;
                    Resources::Interiors::InteriorsShader* m_pInteriorsShader;
                    Resources::Interiors::InteriorsDiffuseTexturedShader* m_pInteriorsDiffuseTexturedShader;
                    Resources::Interiors::InteriorsDiffuseSpecularShader* m_pInteriorsDiffuseSpecularShader;
                    Resources::Interiors::InteriorsDiffuseTranslucentShader* m_pInteriorsDiffuseTranslucentShader;
                    Resources::Interiors::InteriorsCubeMappedShader* m_pInteriorsCubeMappedShader;
                    Resources::Interiors::InteriorsChromeShader* m_pInteriorsChromeShader;
                    Resources::Interiors::InteriorsStencilMirrorShader* m_pInteriorsStencilMirrorShader;
                    Resources::Interiors::InteriorsStencilMirrorMaskShader* m_pInteriorsStencilMirrorMaskShader;
                    
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsDiffuseTexturedMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsDiffuseSpecularMaterialFactory;
                    Resources::Interiors::InteriorsDiffuseTranslucentMaterialFactory* m_pInteriorsDiffuseTranslucentMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsCubeMappedMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsChromeMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsReflectionMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsStencilMirrorMaterialFactory;
                    Resources::Interiors::IInteriorsMaterialFactory* m_pInteriorsStencilMirrorMaskMaterialFactory;
                    
                    
                    Resources::Interiors::InteriorsStencilMirrorClearMaterial* m_pInteriorsStencilMirrorClearMaterial;
                    Eegeo::Rendering::Mesh* m_pFullScreenQuadMesh;
                    Resources::Interiors::InteriorsStencilMirrorClearRenderableFactory* m_pInteriorsStencilMirrorClearRenderableFactory;
                    
                    
                    Resources::Interiors::IInteriorsMaterialService* m_pInteriorsMaterialService;
                    Rendering::IMaterialRepository* m_pInteriorsMaterialRepository;
                    
                    Resources::Interiors::InteriorsDefaultMaterialFactory* m_pInteriorsDefaultMaterialFactory;
                    Resources::Interiors::InteriorsAggregateMaterialFactory* m_pInteriorsAggregateMaterialFactory;
                    
                    Resources::Interiors::IInteriorsTextureResourceBuilder* m_pInteriorsTextureResourceBuilder;
                    Resources::Interiors::IInteriorsCubeTextureResourceBuilder* m_pInteriorsCubeTextureResourceBuilder;
                    
                    Resources::Interiors::InteriorsTextureResourceService* m_pInteriorsTextureResourceService;
                    
                    Resources::Interiors::IInteriorsMaterialAssignmentObserver* m_pInteriorsMaterialAssignmentObserver;
                    
                    
                    Eegeo::Resources::Interiors::IInteriorsMaterialFactory* m_pDynamicContentInteriorsMaterialFactory;
                    Resources::Interiors::Materials::IInteriorsMaterialDtoRepository* m_pInteriorsMaterialDtoRepository;

                    Resources::Interiors::Materials::InteriorsMaterialDescriptorLoader* m_pInteriorsMaterialDescriptorLoader;
                    Resources::Interiors::Materials::InteriorsModelAddedObserver* m_pInteriorsModelAddedObserver;
                    Resources::Interiors::Materials::InteriorsModelRemovedObserver* m_pInteriorsModelRemovedObserver;
                    Resources::Interiors::Materials::InteriorRenderablesRepository* m_pInteriorRenderablesRepository;
                };
            }
        }
    }
}
