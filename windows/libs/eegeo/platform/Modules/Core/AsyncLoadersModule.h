// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "AsyncTexturing.h"
#include "AsyncModels.h"
#include "Web.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "Rendering.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class AsyncLoadersModule : Eegeo::NonCopyable
            {
            public:
                AsyncLoadersModule(Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                   Helpers::IHttpCache& httpCache,
                                   Helpers::ITextureFileLoader& textureLoader
                                   );
                
                
                ~AsyncLoadersModule();
                static AsyncLoadersModule* Create(Web::IWebLoadRequestFactory& webLoadRequestFactory,
                                                  Helpers::IHttpCache& httpCache,
                                                  Helpers::ITextureFileLoader& textureLoader);
                
                Rendering::AsyncTexturing::HttpAsyncTextureLoader& GetHttpAsyncTextureLoader() const;
                Rendering::AsyncTexturing::HttpAsyncCubeTextureLoader& GetHttpAsyncCubeTextureLoader() const;
                Rendering::AsyncTexturing::LocalAsyncTextureLoader& GetLocalAsyncTextureLoader() const;

                Rendering::AsyncTexturing::IAsyncTexture& GetPlaceholderTexture() const;
                Rendering::AsyncTexturing::IAsyncTexture& GetPlaceholderCubeTexture() const;

            private:
                Rendering::AsyncTexturing::HttpAsyncTextureLoader* m_pHttpAsyncTextureLoader;
                Rendering::AsyncTexturing::HttpAsyncCubeTextureLoader* m_pHttpAsyncCubeTextureLoader;
                Rendering::AsyncTexturing::LocalAsyncTextureLoader* m_pLocalAsyncTextureLoader;

				Rendering::AsyncTexturing::IAsyncTexture* m_pProceduralPlaceholder;
				Rendering::AsyncTexturing::IAsyncTexture* m_pProceduralPlaceholderCube;
				Rendering::AsyncTexturing::IAsyncTexture* m_pLoadedPlaceholder;
				Rendering::AsyncTexturing::IAsyncTexture* m_pLoadedPlaceholderCube;
            };
        }
    }
}