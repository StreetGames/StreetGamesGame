// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "Text.h"
#include "Fonts.h"
#include "IAnchoredLabel.h"
#include "OrientedBox2.h"
#include "Camera.h"
#include "LabelStyle.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        namespace LabelViewVisibility
        {
            enum Type
            {
                CulledExceededConstraintRadius,
                CulledGuardBand,
                CulledBehindCamera,
                CulledBehindGlobeHorizon,
                CulledViewportAABB,
                PotentiallyVisible
            };
        }
        
        namespace LabelFadeState
        {
            enum Type
            {
                NotDetermined,
                Off,
                FadingOut,
                FadingIn,
                On
                
            };
        }
        
        struct LabelViewUpdateParams
        {
            m44 InverseViewMatrix;
            bool EnvironmentFlatteningChanged;
            float EnvironmentFlatteningScale;
            v3 ViewProjectionColumnX;
            v3 ViewProjectionColumnY;
            v3 ViewProjectionColumnZ;
            dv3 CameraOrigin;
            v3 CameraEcefUp;
            float CameraAltitude;
            bool PerformHorizonCullOfLabels;
            v2 ViewportOrigin;
            v2 ViewportDimensions;
            Geometry::Bounds2D ViewportBounds;
            float GuardBand;
            float AnchorConstraintRadiusScaleSquared;
            float AnchorConstraintHysteresisSquared;
            float FadeDelta;
            int ZLevel;
        };
        

        struct LabelViewTransforms
        {
            Geometry::OrientedBox2 OrientedBounds;
            Geometry::Bounds2D AxisAlignedBounds;
            v3 AnchorBasisEcefTranslate;
            v2 RotateCosSin;
            v2 Translate;
            bool ExceedsConstraintRadius;
            bool EcefBackFacing;
        };
    
        struct MvpMatrix
        {
            float row0x;
            float row0y;
            float row0w;
            float row3x;
            float row3y;
            float row3w;
            
            inline float DetX() const
            {
                return row0x*row3w - row3x*row0w;
            }
            
            inline float DetY() const
            {
                return row3y*row0w - row0y*row3w;
            }
        };
    
        class LabelView : public Eegeo::NonCopyable
        {
        public:
            typedef IAnchoredLabel::IdType IdType;
            
            LabelView(const IAnchoredLabel& anchoredLabel,
                      const LabelStyle& labelStyle,
                      bool isHidden);
            
            IdType GetId() const;

            bool HasCachedAnchorBasisEcef() const { return m_hasCachedAnchorBasisEcef; }
            
            void UpdateCached(const LabelViewUpdateParams& labelViewUpdateParams);
            
            void UpdateAnchorBasisEcef(const m44& inverseViewMatrix, float environmentFlatteningScale);

            static void UpdateTransformsPrefetch(const LabelView* pLabelView);
            LabelViewVisibility::Type CalcTransformsAndVisibility(const LabelViewUpdateParams& labelViewUpdateParams, LabelViewTransforms& out_result) const;
            
            void SetTransforms(const LabelViewTransforms& transforms);

            static void UpdateFadeStatePrefetch(const LabelView* pLabelView);
            void UpdateFadeState(float dt);
            
            const std::vector<const Text::ShapedGlyph*>& GetShapedGlyphs() const { return m_shapedGlyphs; }
            
            const LabelStyle& GetStyle() const { return *m_pLabelStyle; }
            
            v2 GetTranslate() const { return m_translate; }
            v2 GetRotate() const { return m_rotateCosSin; }
            v2 GetLayoutScale() const { return m_layoutScale; }
            float GetGlyphSizeScale() const { return m_glyphSizeScale; }
            LabelDisplay::Type GetDisplayType() const { return m_displayType; }
            const Geometry::OrientedBox2& GetOrientedBounds() const { return m_orientedBounds; }
            const Geometry::Bounds2D& GetAxisAlignedBounds() const { return m_axisAlignedBounds; }
            
            m44 GetCameraRelativeWorldTransform() const;
            
            int GetPriority() const { return m_priority; }
            float GetFadeParam() const { return m_fadeParam; }
            bool IsOccluded() const { return m_isOccluded; }
            void SetOcclusion(bool isOccluded) { m_isOccluded = isOccluded; }
            bool IsAxisAligned() const { return m_orientationType == LabelOrientation::Screen; }
            
            LabelFadeState::Type GetFadeState() const { return m_fadeState; }
            
            void CalcProjectedConstraintPoints(const Camera::RenderCamera& renderCamera, v2& out_start, v2& out_end) const;
            
            v2 CalcProjectedAnchorPoint(const Camera::RenderCamera& renderCamera) const;
            
            void BeginFadeIn();
            
            bool ShouldDisplayForLevel(int zLevel) const;
            
            bool IsHidden() const { return m_isHidden; }
            void SetHidden(bool hidden) { m_isHidden = hidden; }
            const IAnchoredLabel& GetAnchoredLabel() const { return *m_pAnchoredLabel; }
            
        private:
            bool CalcHasExceededConstraintRadius(const MvpMatrix& mvp, const LabelViewUpdateParams& labelViewUpdateParams) const;
            v2 CalcTranslate(const v2& anchorScreenPos, const v2& rotateCosSin) const;
            v3 CalcAnchorBasisEcefTranslate(const LabelViewUpdateParams& labelViewUpdateParams) const;
            m44 CalcAnchorBasisEcef(const m44& inverseViewMatrix, float environmentFlatteningScale) const;
            m44 GetCachedAnchorBasisEcef() const;
        
            // read from during common hot execution path (UpdateTransformsAndVisibility):
            Geometry::Bounds2D m_localBounds;
            dv3 m_anchorUnflattenedEcef;
            v3 m_anchorOffset;
            v3 m_anchorBasisEcefRight;                  
            v2 m_layoutScale;
            v2 m_alignmentOffset;
            float m_anchorConstraintRadiusEcef;
            float m_precalcConstraintRadiusSq;
            LabelPlacement::Type m_anchorLabelPlacementType;
            LabelOrientation::Type m_orientationType;                   
            LabelFadeState::Type m_fadeState;                           
            LabelDisplay::Type m_displayType;
            bool m_hasCachedAnchorBasisEcef;
            bool m_canCacheAnchorOffset;
            
            inline static int HotWriteFieldsOffset() { return offsetof(LabelView, m_orientedBounds); }
            
            // written to during common hot execution path:
            Geometry::OrientedBox2 m_orientedBounds;
            Geometry::Bounds2D m_axisAlignedBounds;
            v3 m_anchorBasisEcefTranslate;
            v3 m_anchorBasisEcefUp;
            v3 m_anchorBasisEcefForward;
            v2 m_translate;
            v2 m_rotateCosSin;
            bool m_exceedsConstraintRadius;
            
            // cold
            bool m_isOccluded;
            bool m_isEcefBackFacing;
            bool m_isHidden;
            u8 m_minZLevel;
            u8 m_maxZLevel;
            float m_anchorAltitude;
            float m_anchorAltitudeOffset;
            float m_fadeParam;
            float m_glyphSizeScale;
            int m_priority;
            const IAnchoredLabel* m_pAnchoredLabel;
            const LabelStyle* m_pLabelStyle;
            std::vector<const Text::ShapedGlyph*> m_shapedGlyphs;
        };
    }
}
