// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "EegeoWorld.h"
#include "Location.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class CameraTransitionConfiguration 
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
                CameraTransitionConfiguration(
                    const Eegeo::dv3* const pTargetInterestPoint,
                    const float* const pTargetDistanceFromInterest,
                    const float* const pTargetHeadingDegrees,
                    const float* const pTargetTiltDegrees,
                    const float* const pTransitionDurationSeconds,
                    bool jumpIfFarAway,
                    bool allowInterruption
                );

                const Eegeo::dv3& GetTargetInterestPoint() const;
                bool HasTargetInterestPoint() const;

                float GetTargetDistanceFromInterest() const;
                bool HasTargetDistanceFromInterest() const;

                float GetTargetHeadingDegrees() const;
                bool HasTargetHeadingDegrees() const;

                float GetTargetTiltDegrees() const;
                bool HasTargetTiltDegrees() const;

                float GetTransitionDurationSeconds() const;
                bool HasTransitionDurationSeconds() const;

                bool JumpIfFarAway() const;
                bool AllowInterruption() const;
            };
        }
    }
}
