// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "Labels.h"
#include "ShapedText.h"
#include "Bounds.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Labels
    {
        struct LabelCellModelFeature
        {
            Geometry::Bounds2D shapedTextBounds;
            v3 anchorCentreLocalEcef;
            float anchorVerticalOffset;
            float constraintRadiusEcef;
            int glyphIndexStart;
            int glyphCount;
            int anchorVertexStartIndex;
            int anchorVertexCount;
            float anchorSplineParam;
            float scale;
            int labelAnchorCategoryIndex;
            int featureIndex;
        };

    }
}