// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {

        struct OcclusionInput
        {
            float minX;
            float minY;
            float maxX;
            float maxY;
            int priority;
            bool currentlyOccluded;
            // todo - add count of contiguous input elements comprising a composite AABB
        };
        
        struct OcclusionResult
        {
            int inputIndex;
            bool isOccluded;
            
            OcclusionResult(int inputIndex_, bool isOccluded_)
            : inputIndex(inputIndex_)
            , isOccluded(isOccluded_)
            {
            }
        };
        
        class IOcclusionIntersectionPredicate
        {
        public:
            virtual ~IOcclusionIntersectionPredicate() {}
            virtual bool operator()(int inputIndexA, int inputIndexB) const = 0;
        };

        namespace OcclusionResolverMode
        {
            enum Type
            {
                Never,
                IfOccluderNotOccluded,
                Always
            };
        };
        
        
        class IOcclusionResolver
        {
        public:
            typedef std::vector<OcclusionInput> InputListType;
            typedef std::vector<OcclusionResult> ResultsListType;
            
            virtual ~IOcclusionResolver() {}
            
            virtual void Clear() = 0;
            
            virtual void Shrink() = 0;
            
            virtual void SetMode(OcclusionResolverMode::Type occlusionMode) = 0;
            
            virtual InputListType& InputList() = 0;
            
            virtual void Resolve(const IOcclusionIntersectionPredicate& intersectionPredicate) = 0;
            
            // only objects that have changed occlusion state are present on results list
            virtual const ResultsListType& GetResults() const = 0;
        };
    }
}