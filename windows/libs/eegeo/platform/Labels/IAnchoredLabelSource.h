// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ShapedText.h"
#include "VectorMath.h"
#include "LabelCellModelFeature.h"
#include "CellModelAnchoredLabel.h"

#include <string>
#include <vector>


namespace Eegeo
{
    namespace Labels
    {
        class IAnchoredLabelSource
        {
        public:
            typedef std::string IdType;
            
            virtual ~IAnchoredLabelSource() {}
            
            virtual const IdType& GetId() const = 0;
            
            virtual void EnqueueLabels(std::vector<const IAnchoredLabel*>& queue) const = 0;
        };
    }
}