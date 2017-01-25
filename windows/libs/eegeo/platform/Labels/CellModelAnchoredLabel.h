// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Labels.h"
#include "IAnchoredLabel.h"


namespace Eegeo
{
    namespace Labels
    {
        
        class CellModelAnchoredLabel : public IAnchoredLabel
        {
        public:
            CellModelAnchoredLabel(const LabelCellModelFeatureContainer& labelCellModelFeatureContainer,
                                   const LabelCellModelFeature& labelCellModelFeature);
            
            IdType GetId() const;
            
            const std::string& GetEntityName() const;
            
            const LabelAnchorCategory& GetLabelAnchorCategory() const;
            
            void GetShapedGlyphs(std::vector<const Text::ShapedGlyph*>& shapedGlyphs) const;
            
            dv3 GetEcefAnchorPosition() const;
            
            v3 GetAnchorOffset() const;
            
            m44 CalcFeatureAlignedAnchorBasisEcef(float environmentFlatteningScale) const;
            
            Geometry::Bounds2D GetLocalBounds() const;
            
            float GetConstraintRadiusEcef() const;
            
            bool CanCacheAnchorOffset() const { return true; }
            
        private:
        
            const LabelCellModelFeatureContainer& m_labelCellModelFeatureContainer;
            const LabelCellModelFeature& m_labelCellModelFeature;
        };
    }
}