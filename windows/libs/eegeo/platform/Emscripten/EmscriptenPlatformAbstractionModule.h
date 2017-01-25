// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IPlatformAbstractionModule.h"
#include "Types.h"
#include "Helpers.h"
#include "Web.h"
#include "Tasks.h"
#include "Concurrency.h"
#include "Rendering.h"
#include "EmscriptenGlTaskContextFactory.h"
#include "EmscriptenMainThreadWorkPool.h"
#include <string>
#include <set>
#include <EGL/egl.h>

namespace Eegeo
{
    namespace Emscripten
    {
        class EmscriptenPlatformAbstractionModule : public Modules::IPlatformAbstractionModule
        {
        public:
            EmscriptenPlatformAbstractionModule(Helpers::Jpeg::IJpegLoader& jpegLoader,
                                                EGLDisplay& display,
                                                EGLContext& context,
                                                EGLSurface& surface,
                                                const std::string& apiKey);

            ~EmscriptenPlatformAbstractionModule();

            Helpers::ITextureFileLoader& GetTextureFileLoader() const;
            Web::IWebLoadRequestFactory& GetWebLoadRequestFactory() const;
            Web::IWebLoadRequestFactory& GetPlatformWebLoadRequestFactory() const;
            Web::IWebProxySettings& GetProxySettings() const;
            Helpers::IHttpCache& GetHttpCache() const;
            Helpers::IFileIO& GetFileIO() const;
            Helpers::UrlHelpers::IUrlEncoder& GetUrlEncoder() const;
            Concurrency::Tasks::IGlTaskContextFactory& GetGlTaskContextFactory() const;
            Eegeo::Web::IConnectivityService& GetConnectivityService() const;
			Concurrency::Tasks::IWorkPool& GetWorkPool() const;

            void OnPause();
            void OnResume();
            void Update();
            
            void UpdateSurface(EGLSurface& surface);
            void SetWebIOWorkPool(Concurrency::Tasks::IWorkPool* pWorkPool);

        private:
            Helpers::UrlHelpers::IUrlEncoder* m_pUrlEncoder;
            Web::IWebRequestService* m_pWebRequestService;
            Web::IWebLoadRequestFactory* m_pWebLoadRequestFactory;
            Web::IWebLoadRequestFactory* m_pPlatformWebLoadRequestFactory;
            Helpers::IHttpCache* m_pHttpCache;
            Helpers::IFileIO* m_pFileIO;
            Helpers::ITextureFileLoader* m_pTextureFileLoader;
            EmscriptenGlTaskContextFactory* m_pGlTaskContextFactory;
            Eegeo::Web::IConnectivityService* m_pConnectivityService;
            Web::IWebProxySettings* m_pWebProxySettings;
			EmscriptenMainThreadWorkPool* m_pWorkPool;
        };
    }
}