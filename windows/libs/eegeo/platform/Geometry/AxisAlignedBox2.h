// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Geometry.h"

#include "VectorMath.h"

namespace Eegeo
{
    namespace Geometry
    {
        class AxisAlignedBox2
        {
        public:
            
            AxisAlignedBox2();
            
            AxisAlignedBox2(const v2& center,
                            const v2& halfExtents)
            : m_center(center)
            , m_halfExtents(halfExtents)
            {}
            
            v2 GetCenter() const { return m_center; }
            v2 GetHalfExtents() const { return m_halfExtents; }
            
            static AxisAlignedBox2 CreateFromBounds2D(const Bounds2D& bounds2D);
            
        private:
            v2 m_center;
            v2 m_halfExtents;
        };
    }
}