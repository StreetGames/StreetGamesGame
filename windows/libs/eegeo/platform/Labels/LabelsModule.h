// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "Labels.h"
#include "Text.h"
#include "Modules.h"
#include "Rendering.h"
#include "Camera.h"
#include "IFileIO.h"
#include "ICallback.h"
#include "Config.h"
#include "Streaming.h"
#include "LabelsModuleConfiguration.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class LabelsModule : private Eegeo::NonCopyable
        {
        public:
            static LabelsModuleConfiguration DefaultConfig();
            
            static LabelsModule* Create(Text::ScreenTextRenderingModule& screenTextRenderingModule,
                                        Modules::Core::FontsModule& fontsModule,
                                        Modules::Core::DebugRenderingModule& debugRenderingModule,
                                        Helpers::IFileIO& fileIO,
                                        const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                                        const Rendering::ScreenProperties& screenProperties,
                                        const Streaming::ResourceCeilingProvider& resourceCeilingProvider,
                                        const Eegeo::Config::PlatformConfig& platformConfig);
            
            ~LabelsModule();
            
            void Update(float deltaTime, const Camera::RenderCamera& renderCamera);
            
            IAnchoredLabelSourceRepository& GetLabelSourceRepository() const;
            ILabelCellResourceObserver& GetLabelCellResourceObserver() const;
            ILabelOptionsModel& GetLabelOptionsModel() const;
            ILabelOptionsModelObserver& GetLabelOptionsModelObserver() const;
            ILabelFilterModel& GetLabelLayerFilterModel() const;
            ILabelFilterModelObserver& GetLabelLayerFilterModelObserver() const;
            ILabelAnchorFilterModel& GetLabelHiddenFilterModel() const;
            ILabelAnchorFilterModelObserver& GetLabelHiddenFilterModelObserver() const;
            
            ILabelAnchorCategoryRepository& GetLabelAnchorCategoryRepository() const;
            ILabelLayerService& GetLabelLayerService() const;
            const ILabelStyleRepository& GetLabelStyleRepository() const;
            ILabelStyleRepositoryObserver& GetLabelStyleRepositoryObserver() const;
        
        private:
            void OnStyleSheetLoadCompleted(const LabelStyleSheetLoaderResult& result);
        
            void PopulateDefaultAnchorCategories();
            
            void LoadStyleSheet(const std::string& styleSheetUrl);
            
            LabelsModule(IAnchoredLabelSourceRepository* pLabelSourceRepository,
                         ILabelCellResourceObserver* pLabelCellResourceObserver,
                         LabelCellModelController* pLabelCellModelController,
                         ILabelStyleSheetParser* pLabelStyleSheetParser,
                         ILabelTextStyleFactory* pLabelTextStyleFactory,
                         ILabelTextStyleRepository* pLabelTextStyleRepository,
                         ILabelStyleFactory* pLabelStyleFactory,
                         ILabelStyleRepository* pLabelStyleRepository,
                         ILabelStyleRepositoryObserver* pLabelStyleRepositoryObserver,
                         ILabelLayerFactory* pLabelLayerFactory,
                         ILabelLayerIdGenerator* pLabelLayerIdGenerator,
                         ILabelLayerRepository* pLabelLayerRepository,
                         ILabelLayerService* pLabelLayerService,
                         ILabelAnchorCategoryRepository* pLabelAnchorCategoryRepository,
                         ILabelStyleBindingRepository* pLabelStyleBindingRepository,
                         ILabelResourceFontBindingRepository* pLabelResourceFontBindingRepository,
                         ILabelStyleSheetBuilder* pLabelStyleSheetBuilder,
                         ILabelStyleSheetLoader* pLabelStyleSheetLoader,
                         ILabelViewFactory* pLabelViewFactory,
                         ILabelViewRepository* pLabelViewRepository,
                         LabelViewRepositoryObserver* pLabelViewRepositoryObserver,
                         LabelSourceRepositoryObserver* pLabelSourceRepositoryObserver,
                         IOcclusionResolver* pOcclusionResolver,
                         ILabelController* pLabelController,
                         LabelRenderer* pLabelRenderer,
                         LabelOptionsModel* pLabelOptionsModel,
                         LabelFilterModel* pLabelLayerFilterModel,
                         LabelAnchorFilterModel* pLabelHiddenFilterModel,
                         IUpdatable& loaderUpdatable);
        
            IAnchoredLabelSourceRepository* m_pLabelSourceRepository;
            ILabelCellResourceObserver* m_pLabelCellResourceObserver;
            LabelCellModelController* m_pLabelCellModelController;
            ILabelStyleSheetParser* m_pLabelStyleSheetParser;
            ILabelTextStyleFactory* m_pLabelTextStyleFactory;
            ILabelTextStyleRepository* m_pLabelTextStyleRepository;
            ILabelStyleFactory* m_pLabelStyleFactory;
            ILabelStyleRepository* m_pLabelStyleRepository;
            ILabelStyleRepositoryObserver* m_pLabelStyleRepositoryObserver;
            ILabelLayerFactory* m_pLabelLayerFactory;
            ILabelLayerIdGenerator* m_pLabelLayerIdGenerator;
            ILabelLayerRepository* m_pLabelLayerRepository;
            ILabelLayerService* m_pLabelLayerService;
            ILabelAnchorCategoryRepository* m_pLabelAnchorCategoryRepository;
            ILabelResourceFontBindingRepository* m_pLabelResourceFontBindingRepository;
            ILabelStyleBindingRepository* m_pLabelStyleBindingRepository;
            ILabelStyleSheetBuilder* m_pLabelStyleSheetBuilder;
            ILabelStyleSheetLoader* m_pLabelStyleSheetLoader;
            ILabelViewFactory* m_pLabelViewFactory;
            ILabelViewRepository* m_pLabelViewRepository;
            LabelViewRepositoryObserver* m_pLabelViewRepositoryObserver;
            LabelSourceRepositoryObserver* m_pLabelSourceRepositoryObserver;
            IOcclusionResolver* m_pOcclusionResolver;
            ILabelController* m_pLabelController;
            ILabelRenderer* m_pLabelRenderer;
            LabelOptionsModel* m_pLabelOptionsModel;
            LabelFilterModel* m_pLabelLayerFilterModel;
            LabelAnchorFilterModel* m_pLabelHiddenFilterModel;
            IUpdatable& m_loaderUpdatable;
            
            bool m_styleSheetLoaded;
            
            Helpers::TCallback1<LabelsModule, const LabelStyleSheetLoaderResult> m_styleSheetLoadCompleteCallback;
            
        };
    }
}