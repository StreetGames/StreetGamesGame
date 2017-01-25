// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once


#include "Geometry.h"

#include "VectorMath.h"

namespace Eegeo
{
    namespace Geometry
    {
        bool Intersect(const OrientedBox2& boxA, const OrientedBox2& boxB);
        
        bool Intersect(const OrientedBox2& obb, const AxisAlignedBox2& aabb);
    }
}