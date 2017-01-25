// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GlobeCamera.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Camera
    {
        namespace GlobeCamera
        {
            class GlobeCameraModeTransition
            {
            public:
                GlobeCameraModeTransition();
                
                void Begin(const v3& headingStart, const dv3& interestEcef, float tiltStart, float durationSeconds);
                
                bool IsComplete() const { return m_isComplete; }
                
                void Update(float deltaSeconds, const dv3& interestEcef, v3& out_heading, float& out_tilt);
                
            protected:
                v3 m_interestHeadingStart;
                v3 m_interestHeadingEnd;
                float m_tiltStart;
                float m_durationSeconds;
                float m_timeSeconds;
                bool m_isComplete;
            };
        }
    }
}