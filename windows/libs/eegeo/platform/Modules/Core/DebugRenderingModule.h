// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Modules.h"
#include "Helpers.h"
#include "Fonts.h"
#include "DebugRendering.h"
#include "Rendering.h"
#include "Camera.h"
#include "VectorMathDecl.h"
#include "DebugRenderingModuleConfiguration.h"
#include "Text.h"

namespace Eegeo
{
    namespace Modules
    {
        namespace Core
        {
            class DebugRenderingModule : protected Eegeo::NonCopyable
            {
            public:
                DebugRenderingModule(const DebugRenderingModuleConfiguration& config,
                                     Rendering::Shaders::ShaderIdGenerator& shaderIdGenerator,
                                     Rendering::Materials::MaterialIdGenerator& materialIdGenerator,
                                     Rendering::VertexLayouts::VertexLayoutPool& vertexLayoutPool,
                                     Rendering::VertexLayouts::VertexBindingPool& vertexBindingPool,
                                     Rendering::RenderableFilters& renderableFilters,
                                     Fonts::IFontInstanceService& fontInstanceService,
                                     Text::IScreenTextRenderer& screenTextRenderer);
                
                ~DebugRenderingModule();
                
                static DebugRenderingModuleConfiguration DefaultConfig();
                
                static DebugRenderingModule* Create(const DebugRenderingModuleConfiguration& config,
                                                    Core::RenderingModule& renderingModule,
                                                    FontsModule& fontsModule,
                                                    Text::ScreenTextRenderingModule& screenTextRenderingModule);
                
                DebugRendering::DebugRenderer& GetDebugRenderer() const;
                const Fonts::FontInstance& GetDebugFont() const;
                
                void Update(float dt, const Camera::RenderCamera& renderCamera);
            private:
                DebugRendering::DebugRenderer *m_pDebugRenderer;
                
                Rendering::Shaders::ColoredVertShader* m_pColoredVertShader;
                Rendering::Materials::DebugMaterial* m_pDebugMaterial;

                Fonts::IFontInstanceService& m_fontInstanceService;
                const Fonts::FontInstance* m_pDebugFont;
            };
        }
    }
}