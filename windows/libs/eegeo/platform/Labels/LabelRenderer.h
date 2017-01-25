// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "Text.h"
#include "ShapedGlyph.h"
#include "DebugRendering.h"
#include "Geometry.h"
#include "Camera.h"
#include "StencilMapLayerMask.h"
#include "LabelStyle.h"
#include "LayerIds.h"
#include "Rendering.h"

#include <vector>



namespace Eegeo
{
    namespace Labels
    {
        namespace DebugDrawMode
        {
            enum Type
            {
                DrawAABB,
                DrawOBB,
                DrawAnchor,
                DrawConstraints,
                IdentifyStyle
            };
          
            inline u32 ToFlag(Type debugDrawMode)
            {
                return 1 << debugDrawMode;
            }
        };
        
        class ILabelRenderer
        {
        public:
            virtual ~ILabelRenderer() {}
            
            virtual void Draw() = 0;
            
            virtual void DrawLabelDebug(const Camera::RenderCamera& renderCamera, const LabelView& labelView, u32 debugDrawModeFlags) = 0;
            
            virtual std::vector<const LabelView*>& GetViewList() = 0;
        };
        
        class LabelRenderer : public ILabelRenderer, private Eegeo::NonCopyable
        {
        public:
            LabelRenderer(Text::IScreenTextRenderer& screenTextRenderer,
                          Text::IWorldTextRenderer& worldTextRenderer,
                          DebugRendering::DebugRenderer& debugRenderer,
                          const Rendering::EnvironmentFlatteningService& environmentFlatteningService,
                          u32 mapLayersStencilMask,
                          const Rendering::LayerIds::Values renderLayer
                          );
            
            void Draw();
            
            void DrawLabelDebug(const Camera::RenderCamera& renderCamera, const LabelView& labelView, u32 debugDrawModeFlags);
            
            std::vector<const LabelView*>& GetViewList() { return m_viewList; }
        private:
        
            enum FlattenMode
            {
                NotFlattened,
                Transitioning,
                Flattened
            };

            void DrawLabel(const LabelView& labelView, FlattenMode flattenMode, float flattenParam);
            
            void DebugDrawOBB(const Geometry::OrientedBox2& obb);
            void DebugDrawAABB(const Geometry::Bounds2D& aabb, const v4& color);
            void DebugDrawPoint(const v2& p);
            void DebugDrawConstraints(const Camera::RenderCamera& renderCamera, const LabelView& labelView);
            

            StencilMode::Type CalcStencilMode(Text::ITextRenderer& textRenderer, const LabelStyle& labelStyle, FlattenMode flattenMode);
            v4 CalcMaskedColor(const v4& nonMaskedColor, const v4& maskedColor, StencilMode::Type stencilMode, FlattenMode flattenMode, float flattenParam) const;
            
            Text::IScreenTextRenderer& m_screenTextRenderer;
            Text::IWorldTextRenderer& m_worldTextRenderer;
            DebugRendering::DebugRenderer& m_debugRenderer;
            const Rendering::EnvironmentFlatteningService& m_environmentFlatteningService;
            
            std::vector<const LabelView*> m_viewList;
            
            const LabelStyle* m_pPrevStyleScreen;
            const LabelStyle* m_pPrevStyleWorld;
            
            const u32 m_mapLayersStencilMask;
            const Rendering::LayerIds::Values m_renderLayer;
        };
    }
}
