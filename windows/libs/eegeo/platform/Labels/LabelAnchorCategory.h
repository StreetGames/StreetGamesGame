// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "Text.h"
#include "Fonts.h"
#include "LabelLayer.h"

#include <string>

namespace Eegeo
{
    namespace Labels
    {
        namespace LabelPlacement
        {
            enum Type
            {
                Point,
                Line
            };
        }
        
        class LabelAnchorCategory : public Eegeo::NonCopyable
        {
        public:
            typedef std::string IdType;
            
            static LabelAnchorCategory* Create(const std::string& labelAnchorCategory, LabelLayer::IdType labelLayerId, int minLevel, int maxLevel, LabelPlacement::Type labelPlacement);

            const IdType& GetId() const { return m_id; }
            
            LabelLayer::IdType GetLabelLayerId() const { return m_labelLayerId; }
            
            int GetMinLevel() const { return m_minLevel; }
            
            int GetMaxLevel() const { return m_maxLevel; }

            LabelPlacement::Type GetLabelPlacement() const { return m_labelPlacement; }
            
        private:
            LabelAnchorCategory(const IdType& labelAnchorCategoryId, LabelLayer::IdType labelLayerId, int minLevel, int maxLevel, LabelPlacement::Type labelPlacement);
        
            IdType m_id;
            LabelLayer::IdType m_labelLayerId;
            int m_minLevel;
            int m_maxLevel;
            LabelPlacement::Type m_labelPlacement;
        };
    }
}