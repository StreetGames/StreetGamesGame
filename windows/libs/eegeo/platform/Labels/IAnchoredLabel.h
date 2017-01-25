// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Labels.h"
#include "Text.h"
#include "VectorMath.h"
#include "Bounds.h"
#include "LabelAnchorCategory.h"

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class IAnchoredLabel
        {
        public:
            typedef std::string IdType;
            
            virtual ~IAnchoredLabel() {;}
            
            virtual IdType GetId() const = 0;
            
            virtual const std::string& GetEntityName() const = 0;
            
            virtual const LabelAnchorCategory& GetLabelAnchorCategory() const = 0;
            
            virtual void GetShapedGlyphs(std::vector<const Text::ShapedGlyph*>& shapedGlyphs) const = 0;
            
            virtual dv3 GetEcefAnchorPosition() const = 0;
            
            virtual v3 GetAnchorOffset() const = 0;
            
            virtual m44 CalcFeatureAlignedAnchorBasisEcef(float environmentFlatteningScale) const = 0;
            
            virtual Geometry::Bounds2D GetLocalBounds() const = 0;
            
            virtual float GetConstraintRadiusEcef() const = 0;
            
            virtual bool CanCacheAnchorOffset() const = 0;
        };
    }
}