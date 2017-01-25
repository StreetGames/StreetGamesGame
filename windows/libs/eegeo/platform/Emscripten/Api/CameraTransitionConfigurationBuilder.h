// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Location.h"
#include "VectorMath.h"
#include "CameraTransitionConfiguration.h"

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class CameraTransitionConfigurationBuilder
            {
                Eegeo::dv3 m_targetInterestPoint;
                bool m_hasTargetInterestPoint;
                float m_targetDistanceFromInterest;
                bool m_hasTargetDistanceFromInterest;
                float m_targetHeadingDegrees;
                bool m_hasTargetHeadingDegrees;
                float m_targetTiltDegrees;
                bool m_hasTargetTiltDegrees;
                float m_transitionDurationSeconds;
                bool m_hasTransitionDurationSeconds;
                bool m_jumpIfFarAway;
                bool m_allowInterruption;  
                
            public:
                CameraTransitionConfigurationBuilder();
                
                CameraTransitionConfiguration Build();

                CameraTransitionConfigurationBuilder& SetTargetInterestPointTo(const Eegeo::dv3& targetInterestPoint);
                CameraTransitionConfigurationBuilder& SetTargetDistanceFromInterestTo(float targetDistanceFromInterest);
                CameraTransitionConfigurationBuilder& SetTargetHeadingDegreesTo(float targetHeadingDegrees);
                CameraTransitionConfigurationBuilder& SetTargetTiltDegreesTo(float targetTiltDegrees);
                CameraTransitionConfigurationBuilder& SetTransitionDurationSecondsTo(float transitionDurationSeconds);
                CameraTransitionConfigurationBuilder& EnableJumpIfFarAway();
                CameraTransitionConfigurationBuilder& EnableInterruption();
            };
        }
    }
}
