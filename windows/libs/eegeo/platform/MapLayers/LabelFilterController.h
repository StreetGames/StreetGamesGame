// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#include "MapLayers.h"
#include "Types.h"
#include "Labels.h"
#include "Interiors.h"
#include "LabelLayer.h"

#include "ICallback.h"

#include <vector>

namespace Eegeo
{
    namespace MapLayers
    {
        class LabelFilterController : private Eegeo::NonCopyable
        {
        public:
            LabelFilterController(Labels::ILabelFilterModel& labelLayerFilterModel,
                                  Resources::Interiors::InteriorTransitionModel& interiorTransitionModel,
                                  const Labels::LabelLayer::IdType& interiorsLabelLayerId);
            
            virtual ~LabelFilterController();
        private:
            void OnInteriorTransitionModelChanged();
            
            void RefreshLabelFilter();
        
            Labels::ILabelFilterModel& m_labelLayerFilterModel;
            Resources::Interiors::InteriorTransitionModel& m_interiorTransitionModel;
            Labels::LabelLayer::IdType m_interiorsLabelLayerId;
            
            
            Helpers::TCallback0<LabelFilterController> m_interiorTransitionModelChanged;
            
            std::vector<Labels::LabelLayer::IdType> m_labelLayerIds;
        };
        
    }
}