// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"
#include "ShapedText.h"
#include "VectorMath.h"
#include "LabelCellModelFeature.h"

#include <string>
#include <vector>


namespace Eegeo
{
    namespace Labels
    {
        class LabelCellModelFeatureContainer
        {
        public:
            LabelCellModelFeatureContainer(const dv3& originEcef,
                                           const v3& upEcef,
                                           int cubeFaceIndex,
                                           const std::vector<Text::ShapedGlyph>* pShapedGlyphPool,
                                           const std::vector<v3>* pAnchorVertices,
                                           const std::vector<const LabelAnchorCategory*>* pLabelAnchorCategories,
                                           const std::vector<LabelCellModelFeature>* pLabelFeaturePool,
                                           const std::vector<std::string>* pLabelIdPool,
                                           const std::vector<std::string>* pEntityNames);
            
            ~LabelCellModelFeatureContainer();
            
            dv3 GetOriginEcef() const { return m_originEcef; }
            
            v3 GetUpEcef() const { return m_upEcef; }
            
            int GetCubeFaceIndex() const { return m_cubeFaceIndex; }
            
            const std::vector<Text::ShapedGlyph>& GetShapedGlyphPool() const { return *m_pShapedGlyphPool; }
            
            const std::vector<v3>& GetAnchorVertexPool() const { return *m_pAnchorVertexPool; }
            
            const std::vector<const LabelAnchorCategory*>& GetLabelAnchorCategoryPool() const { return *m_pLabelAnchorCategoryPool; }
            
            const std::vector<std::string>& GetLabelIdPool() const { return *m_pLabelIdPool; }
            
            const std::vector<std::string>& GetEntityNames() const { return *m_pEntityNames; }
            
        private:
            dv3 m_originEcef;
            v3 m_upEcef;
            int m_cubeFaceIndex;
            const std::vector<Text::ShapedGlyph>* m_pShapedGlyphPool;
            const std::vector<v3>* m_pAnchorVertexPool;
            const std::vector<const LabelAnchorCategory*>* m_pLabelAnchorCategoryPool;
            const std::vector<LabelCellModelFeature>* m_pLabelFeaturePool;
            const std::vector<std::string>* m_pLabelIdPool;
            const std::vector<std::string>* m_pEntityNames;
            
        };
    }
}