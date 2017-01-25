// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Interiors.h"
#include "InteriorsMaterials.h"
#include "Rendering.h"
#include "Modules.h"
#include "CityThemes.h"
#include "AsyncTexturing.h"
#include "Collision.h"
#include "IdTypes.h"
#include "Lighting.h"
#include "Helpers.h"
#include "Labels.h"
#include "LabelLayer.h"
#include "ICallback.h"
#include "Config.h"

#include <string>

namespace Eegeo
{
    namespace Modules
    {
        namespace Map
        {
            namespace Layers
            {
                class InteriorsStreamingModule : private Eegeo::NonCopyable
                {
                public:
                    virtual ~InteriorsStreamingModule();
                    
                    static InteriorsStreamingModule* Create(Modules::Core::RenderingModule& renderingModule,
                                                            Core::FontsModule& fontsModule,
                                                            Labels::LabelsModule& labelsModule,
                                                            Modules::Map::Layers::InteriorsModelModule& interiorsModelModule,
                                                            Modules::Map::Layers::InteriorsMaterialsModule& interiorsMaterialsModule,
                                                            Rendering::MeshFactories::PackedDiffuseReadMeshFactory& packedDiffuseReadMeshFactory,
                                                            Helpers::IFileIO& fileIO,
                                                            const Eegeo::Config::PlatformConfig& platformConfig);
                    
                    virtual Resources::Interiors::InteriorsStreaming& GetInteriorsStream() const;
                    
                    virtual Resources::Interiors::Markers::InteriorMarkersCellResourceBuilder& GetInteriorMarkersCellResourceBuilder() const;
                    
                    virtual Labels::LabelLayer::IdType GetLabelLayerId() const { return m_labelLayerId; }
                    
                    virtual void Update(float dt);
                
                private:
                
                    InteriorsStreamingModule(Resources::Interiors::InteriorsStreaming* pInteriorsStreaming,
                                             Resources::Interiors::Builder::ChunkedInteriorsBuilder* pChunkedInteriorsBuilder,
                                             Resources::Interiors::Markers::InteriorMarkersCellResourceBuilder* pInteriorMarkersCellResourceBuilder,
                                             Resources::Interiors::Builder::IInteriorLabelAnchorCategoryMapperFactory* pInteriorLabelAnchorCategoryMapperFactory,
                                             Resources::Interiors::Builder::IInteriorLabelAnchorCategoryMapper* pInteriorLabelAnchorCategoryMapper,
                                             Resources::Interiors::Builder::IInteriorLabelBuilder* pInteriorLabelBuilder,
                                             Resources::Interiors::IInteriorLabelCategoryLoader* pInteriorLabelCategoryLoader,
                                             Resources::Interiors::IInteriorLabelCategoryParser* pInteriorLabelCategoryParser,
                                             Resources::Interiors::IUpdatableLoader& interiorLabelCategoryLoaderUpdatable,
                                             const Labels::LabelLayer::IdType labelLayerId);
                    
                    
                    void OnLabelCategoryLoadCompleted(const Resources::Interiors::InteriorLabelCategoryLoaderResult& result);
                    
                    void LoadLabelCategories(const std::string& interiorLabelCategoriesUrl);
                    
                    
                    Resources::Interiors::InteriorsStreaming* m_pInteriorsStreaming;
                    Resources::Interiors::Builder::ChunkedInteriorsBuilder* m_pChunkedInteriorsBuilder;
                    Resources::Interiors::Markers::InteriorMarkersCellResourceBuilder* m_pInteriorMarkersCellResourceBuilder;
                    Resources::Interiors::Builder::IInteriorLabelAnchorCategoryMapperFactory* m_pInteriorLabelAnchorCategoryMapperFactory;
                    Resources::Interiors::Builder::IInteriorLabelAnchorCategoryMapper* m_pInteriorLabelAnchorCategoryMapper;
                    Resources::Interiors::Builder::IInteriorLabelBuilder* m_pInteriorLabelBuilder;
                    Resources::Interiors::IInteriorLabelCategoryLoader* m_pInteriorLabelCategoryLoader;
                    Resources::Interiors::IInteriorLabelCategoryParser* m_pInteriorLabelCategoryParser;
                    Resources::Interiors::IUpdatableLoader& m_interiorLabelCategoryLoaderUpdatable;
                    const Labels::LabelLayer::IdType m_labelLayerId;
                    
                    
                    bool m_interiorLabelCategoriesLoaded;
                    
                    Helpers::TCallback1<InteriorsStreamingModule, const Resources::Interiors::InteriorLabelCategoryLoaderResult> m_labelCategoriesLoadCompleteCallback;
                };
            }
        }
    }
}