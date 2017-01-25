// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IAnchoredLabelSource.h"
#include "Labels.h"
#include "ShapedText.h"
#include "VectorMath.h"
#include "LabelCellModelFeature.h"
#include "LabelCellModelFeatureContainer.h"


#include <string>
#include <vector>


namespace Eegeo
{
    namespace Labels
    {
        
        class TransformedCellModelAnchoredLabel : public IAnchoredLabel
        {
        public:
            TransformedCellModelAnchoredLabel(const IAnchoredLabel& sourceAnchoredLabel);
            
            IdType GetId() const { return m_sourceAnchoredLabel.GetId(); }
            
            const std::string& GetEntityName() const { return m_sourceAnchoredLabel.GetEntityName(); }
            
            const LabelAnchorCategory& GetLabelAnchorCategory() const { return m_sourceAnchoredLabel.GetLabelAnchorCategory(); }
            
            void GetShapedGlyphs(std::vector<const Text::ShapedGlyph*>& shapedGlyphs) const { m_sourceAnchoredLabel.GetShapedGlyphs(shapedGlyphs); }
            
            dv3 GetEcefAnchorPosition() const;
            
            v3 GetAnchorOffset() const;
            
            m44 CalcFeatureAlignedAnchorBasisEcef(float environmentFlatteningScale) const;
            
            Geometry::Bounds2D GetLocalBounds() const { return m_sourceAnchoredLabel.GetLocalBounds(); }
            
            float GetConstraintRadiusEcef() const { return m_sourceAnchoredLabel.GetConstraintRadiusEcef(); }
            
            bool CanCacheAnchorOffset() const { return false; }
            
            
            const IAnchoredLabel& GetSourceAnchoredLabel() const { return m_sourceAnchoredLabel; }
            
            void SetTransformedOffset(const v3& tranformedAnchorOffset);
            
            void SetShouldDraw(bool shouldDraw);
            
            bool ShouldDraw() const { return m_shouldDraw; }
            
        private:
            v3 m_tranformedAnchorOffset;
            const IAnchoredLabel& m_sourceAnchoredLabel;
            
            bool m_shouldDraw;
        };
    }
}