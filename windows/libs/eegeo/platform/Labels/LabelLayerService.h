// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "LabelLayer.h"
#include "Types.h"

namespace Eegeo
{
    namespace Labels
    {
        class ILabelLayerService
        {
        public:
            virtual ~ILabelLayerService() {}
            
            virtual LabelLayer::IdType Register(const std::string& labelLayerName) = 0;
            
            virtual bool FindLabelLayer(const std::string& labelLayerName, LabelLayer::IdType& out_layerId) const = 0;
        };
        
        class LabelLayerService : public ILabelLayerService, private Eegeo::NonCopyable
        {
        public:
            LabelLayerService(Labels::ILabelLayerFactory& labelLayerFactory,
                              Labels::ILabelLayerRepository& labelLayerRepository);
            
            ~LabelLayerService();
            
            LabelLayer::IdType Register(const std::string& labelLayerName);
            
            bool FindLabelLayer(const std::string& labelLayerName, LabelLayer::IdType& out_layerId) const;
        private:
            Labels::ILabelLayerFactory& m_labelLayerFactory;
            Labels::ILabelLayerRepository& m_labelLayerRepository;
        };
    }
}