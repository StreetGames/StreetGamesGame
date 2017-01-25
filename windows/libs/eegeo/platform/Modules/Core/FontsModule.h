// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "AsyncTexturing.h"
#include "Shader.h"
#include "EnvironmentCharacterSet.h"
#include "Helpers.h"
#include "Modules.h"
#include "FontsModuleConfiguration.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class FontsModule : protected Eegeo::NonCopyable
            {
            public:
                static FontsModuleConfiguration DefaultConfig();
                
                static FontsModuleConfiguration LegacyPatchedConfig(const FontsModuleConfiguration& config, EnvironmentCharacterSet::Type characterSetType);
                
                static FontsModule* Create(
                    const FontsModuleConfiguration& config,
                    RenderingModule& renderingModule,
                    Helpers::IFileIO& fileIO,
                    AsyncLoadersModule& asyncLoadersModule
                );

                ~FontsModule();             
                
                const Fonts::FontInstance& GetEnvironmentFont() const;
                const Rendering::Shaders::TextShaderSet& GetTextShaderSet() const;
                Fonts::IFontInstanceService& GetFontInstanceService() const;

            private:
                FontsModule(
                    const FontsModuleConfiguration& config,
                    Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                    Helpers::IFileIO& fileIO,
                    Rendering::AsyncTexturing::IAsyncTextureRequestor& asyncTextureRequestor
                );
                
                void LoadResources(const FontsModuleConfiguration& config);
                void ReleaseResources();
                
                Fonts::FontLoader* m_pFontLoader;
                Fonts::FontInstanceRepository* m_pFontInstanceRepository;
                Fonts::IFontInstanceIdBuilder* m_pFontInstanceIdBuilder;
                Fonts::IFontInstanceService* m_pFontInstanceService;
                const Fonts::FontInstance* m_pEnvironmentFont;
                Rendering::Shaders::TextShader* m_pTextShaderNoOutline;
                Rendering::Shaders::TextShader* m_pTextShaderWithOutline;
                Rendering::Shaders::SdfTextShader* m_pTextShaderSdfNull;
                Rendering::Shaders::SdfTextShader* m_pTextShaderSdfUniformScale;
                Rendering::Shaders::SdfTextShader* m_pTextShaderSdfUniformScaleSuperSampled;
                Rendering::Shaders::SdfTextShader* m_pTextShaderSdf;
                Rendering::Shaders::SdfTextShader* m_pTextShaderSdfSuperSampled;
                Rendering::Shaders::TextShaderSet* m_pTextShaderSet;
            };
        }
    }
}