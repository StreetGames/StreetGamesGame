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
        class LabelCellModel : public IAnchoredLabelSource, private Eegeo::NonCopyable
        {
        public:
            static LabelCellModel* Create(const IdType& cellModelId,
                                          const dv3& originEcef,
                                          const v3& upEcef,
                                          int cubeFaceIndex,
                                          const std::vector<Text::ShapedGlyph>* pShapedGlyphPool,
                                          const std::vector<v3>* pAnchorVertexPool,
                                          const std::vector<const LabelAnchorCategory*>* pLabelAnchorCategoryPool,
                                          const std::vector<LabelCellModelFeature>* pLabelFeaturePool,
                                          const std::vector<std::string>* pEntityNames);

            ~LabelCellModel();
            
            const IdType& GetId() const { return m_id; }
            
            void EnqueueLabels(std::vector<const IAnchoredLabel*>& labels) const;
            
            const std::vector<CellModelAnchoredLabel>& GetAnchoredLabelPool() const { return *m_pAnchoredLabelPool; }
            
        private:
        
            LabelCellModel(const IdType& cellModelId,
                           const LabelCellModelFeatureContainer* pLabelCellModelFeatureContainer,
                           const std::vector<CellModelAnchoredLabel>* pAnchoredLabelPool
                           );
            
            IdType m_id;
            const LabelCellModelFeatureContainer* m_pLabelCellModelFeatureContainer;
            const std::vector<CellModelAnchoredLabel>* m_pAnchoredLabelPool;

        };

    }
}