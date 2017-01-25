// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Types.h"
#include "IAnchoredLabelSource.h"
#include "Labels.h"
#include "ShapedText.h"
#include "VectorMath.h"
#include "LabelCellModelFeature.h"
#include "LabelCellModelFeatureContainer.h"
#include "TransformedCellModelAnchoredLabel.h"

#include <string>
#include <vector>


namespace Eegeo
{
    namespace Labels
    {
        class TransformedLabelCellModel : public IAnchoredLabelSource, private Eegeo::NonCopyable
        {
        public:
            
            static TransformedLabelCellModel* Create(const LabelCellModel& labelCellModel);
            
            ~TransformedLabelCellModel();
            
            const IdType& GetId() const;
            
            void EnqueueLabels(std::vector<const IAnchoredLabel*>& queue) const;
            
            void SetTransform(const m44& transform, const dv3& pivot);
            
        private:
            TransformedLabelCellModel(const LabelCellModel& labelCellModel,
                                      std::vector<TransformedCellModelAnchoredLabel>* pTransformedCellModelAnchoredLabels);
            
            void UpdateLabels();
            
            const LabelCellModel& m_labelCellModel;

            std::vector<TransformedCellModelAnchoredLabel>* m_pTransformedCellModelAnchoredLabels;
        };
    }
}