// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Geometry.h"

#include "VectorMath.h"

namespace Eegeo
{
    namespace Geometry
    {
        class OrientedBox2
        {
        public:
            
            OrientedBox2();
            
            OrientedBox2(const v2& center,
                         const v2& axisX,
                         const v2& axisY,
                         const v2& halfExtents);
            
            v2 GetCenter() const { return m_center; }
            v2 GetAxisX() const { return m_axisX; }
            v2 GetAxisY() const { return m_axisY; }
            v2 GetHalfExtents() const { return m_halfExtents; }
            
            Geometry::Bounds2D CalcAxisAlignedBounds() const;

        private:
            v2 m_center;
            v2 m_axisX;
            v2 m_axisY;
            v2 m_halfExtents;
        };
    }
}