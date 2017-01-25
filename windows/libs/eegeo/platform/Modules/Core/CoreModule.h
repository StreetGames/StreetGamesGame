// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Rendering.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "Web.h"
#include "EnvironmentCharacterSet.h"
#include "IdTypes.h"
#include "Config.h"
#include "Text.h"
#include "AsyncTexturing.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class CoreModule : protected Eegeo::NonCopyable
            {
            public:

                ~CoreModule();
                
                static CoreModule* Create(
                                          const Config::PlatformConfig& platformConfig,
                                          const Modules::IPlatformAbstractionModule& platformAbstractionModule
                                         );
                
                RenderingModule& GetRenderingModule() const;
                LightingModule& GetLightingModule() const;
                FontsModule& GetFontsModule() const;
                AsyncLoadersModule& GetAsyncLoadersModule() const;
                DebugRenderingModule& GetDebugRenderingModule() const;
                SceneModelsModule& GetSceneModelsModule() const;
                Text::ScreenTextRenderingModule& GetScreenTextRenderingModule() const;
                        
            private:
                CoreModule(
                           RenderingModule* pRenderingModule,
                           LightingModule* pLightingModule,
                           FontsModule* pFontsModule,
                           AsyncLoadersModule* pAsyncLoadersModule,
                           DebugRenderingModule* pDebugRenderingModule,
                           SceneModelsModule* pSceneModelsModule,
                           Text::ScreenTextRenderingModule* pScreenTextRenderingModule
                           );
                
                RenderingModule* m_pRenderingModule;
                LightingModule* m_pLightingModule;
                FontsModule* m_pFontsModule;
                AsyncLoadersModule* m_pAsyncLoadersModule;
                DebugRenderingModule* m_pDebugRenderingModule;
                SceneModelsModule* m_pSceneModelsModule;
                Text::ScreenTextRenderingModule* m_pScreenTextRenderingModule;
            };
        }
    }
}