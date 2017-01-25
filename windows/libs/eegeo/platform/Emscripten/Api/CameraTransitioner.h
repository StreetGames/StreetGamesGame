// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "EegeoWorld.h"
#include "Location.h"
#include "GlobeCamera.h"
#include "VectorMath.h"
#include "ICallback.h"
#include "CallbackCollection.h"
#include "CameraTransitionConfiguration.h"

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class CameraTransitioner
            {
            public:
                CameraTransitioner(Eegeo::Camera::GlobeCamera::GlobeCameraController& cameraController, bool shouldSnapToTerrain);
                
                bool TryStartTransitionTo(const CameraTransitionConfiguration& configuration);
                void StopCurrentTransition();
                void Update(float dt);

                bool TryInterruptTransition();
                
                const bool IsTransitioning() const
                {
                    return m_isTransitioning;
                }

                void RegisterTransitionStoppedCallback(Helpers::ICallback0& callback);
                void UnregisterTransitionStoppedCallback(Helpers::ICallback0& callback);
                
            private:
                void StartTransitionTo(const CameraTransitionConfiguration& configuration);
                void StartAnimatedTransition();
                void SnapToEndTransition();
                bool ShouldJumpTo(Eegeo::dv3 newInterestPoint);

                Eegeo::dv3 GetTargetInterestPoint(const CameraTransitionConfiguration& configuration);
                float GetTargetHeading(const CameraTransitionConfiguration& configuration);
                float GetTargetDistanceFromInterest(const CameraTransitionConfiguration& configuration);
                float GetTargetTilt(const CameraTransitionConfiguration& configuration);

                float ComputeTransitionDuration(
                    const CameraTransitionConfiguration& configuration,
                    const Eegeo::dv3& startEcef,
                    const Eegeo::dv3 endEcef
                );
                
                Eegeo::Camera::GlobeCamera::GlobeCameraController& m_cameraController;
                Eegeo::dv3 m_startTransitionInterestPoint;
                Eegeo::dv3 m_endTransitionInterestPoint;
                float m_startInterestDistance;
                float m_endInterestDistance;
                float m_startTransitionHeading;
                float m_endTransitionHeading;
                float m_startTiltDegrees;
                float m_endTiltDegrees;
                float m_transitionTime;
                float m_transitionDuration;
                bool m_isTransitioning;
                bool m_interruptsEnabled;
                bool m_shouldSnapToTerrain;

                Helpers::CallbackCollection0 m_transitionStoppedCallbacks;
            };
        }
    }
}