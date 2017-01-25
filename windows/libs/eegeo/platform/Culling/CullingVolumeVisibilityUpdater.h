// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Culling.h"
#include "Types.h"
#include "Geometry.h"
#include "VectorMathDecl.h"

#include <vector>

namespace Eegeo
{
    namespace Culling
    {
        class CullingVolumeVisibilityUpdater : private Eegeo::NonCopyable
        {
        public:
            CullingVolumeVisibilityUpdater(int minTrianglesForTreeDescent);
            
            virtual ~CullingVolumeVisibilityUpdater() {;}
            
            virtual void ComputeVisibleRanges(const CullingVolumeTree& cullingVolumeTree, const dv3& frustumOrigin, const Geometry::Frustum& frustum, std::vector<IndexBufferRange>& visibleRanges, float environmentScale);
            
        private:
            struct StackEntry
            {
                StackEntry();
                
                StackEntry(int cullingVolumeIndex, u32 inactivePlaneFlags)
                : cullingVolumeIndex(cullingVolumeIndex)
                , inactivePlaneFlags(inactivePlaneFlags)
                {}
                
                int cullingVolumeIndex;
                u32 inactivePlaneFlags;
            };
            
            struct InternalIndexBufferRange
            {
                InternalIndexBufferRange(int startIndex, int indexCount)
                : startIndex(startIndex)
                , indexCount(indexCount)
                {
                    
                }
                
                int startIndex;
                int indexCount;
            };
            
            std::vector<StackEntry> m_stack;
            std::vector<InternalIndexBufferRange> m_indexBufferRanges;
            
            int m_minIndicesForTreeDescent;
            
            void ComputeVisibleRangesInTree(const CullingVolumeTree& cullingVolumeTree, const dv3& cameraEcefOrigin, const v4 planes[], float scale);
            
            void BuildMergedRanges(std::vector<IndexBufferRange>& visibleRanges) const;
        };
    }
}