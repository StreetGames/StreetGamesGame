// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "LabelView.h"
#include "IntersectionOrientedBox2.h"
#include "IOcclusionResolver.h"
#include "AxisAlignedBox2.h"

#include <vector>

namespace Eegeo
{
    namespace Labels
    {
        class LabelViewIntersectionPredicate : public IOcclusionIntersectionPredicate
        {
        public:
            LabelViewIntersectionPredicate(const std::vector<LabelView*>& labelViews)
            : m_labelViews(labelViews)
            {}
            
            bool operator()(int ia, int ib) const
            {
                const LabelView& a = *m_labelViews[ia];
                const LabelView& b = *m_labelViews[ib];
                
                const bool isAxisAlignedA = a.IsAxisAligned();
                const bool isAxisAlignedB = b.IsAxisAligned();
                
                if (!(isAxisAlignedA || isAxisAlignedB))
                {
                    return Geometry::Intersect(a.GetOrientedBounds(), b.GetOrientedBounds());
                }
                
                if (isAxisAlignedA != isAxisAlignedB)
                {
                    if (a.IsAxisAligned())
                    {
                        return Geometry::Intersect(b.GetOrientedBounds(), Geometry::AxisAlignedBox2::CreateFromBounds2D(a.GetAxisAlignedBounds()));
                    }
                    else
                    {
                        return Geometry::Intersect(a.GetOrientedBounds(), Geometry::AxisAlignedBox2::CreateFromBounds2D(b.GetAxisAlignedBounds()));
                    }
                }
                
                return true; // both axis aligned, so broadphase AABB test was already sufficient                
            }
            
        private:
            const std::vector<LabelView*>& m_labelViews;
        };
        
        


    }
}