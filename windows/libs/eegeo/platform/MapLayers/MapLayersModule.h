// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "MapLayers.h"
#include "Labels.h"
#include "Modules.h"
#include "Types.h"

namespace Eegeo
{
    namespace MapLayers
    {
        class MapLayersModule : private Eegeo::NonCopyable
        {
        public:
            static MapLayersModule* Create(Labels::LabelsModule& labelsModule,
                                           Modules::Map::Layers::InteriorsPresentationModule& interiorsPresentationModule,
                                           Modules::Map::Layers::InteriorsStreamingModule& interiorsStreamingModule);
            
            virtual ~MapLayersModule();
        private:
            MapLayersModule(LabelFilterController* pLabelFilterController);
            
            LabelFilterController* m_pLabelFilterController;
        };

    }
}