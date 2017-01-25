#pragma once

#include "Types.h"
#include "LatLongAltitude.h"
#include "GpsGlobeCameraController.h"
#include "CameraTransitioner.h"
#include "Interiors.h"
#include "VectorMath.h"

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            typedef void (*TCameraEventCallback)(int);
            enum CameraEventType
            {
                Move,
                MoveStart,
                MoveEnd,
                Drag,
                DragStart,
                DragEnd,
                Pan,
                PanStart,
                PanEnd,
                Rotate,
                RotateStart,
                RotateEnd,
                Tilt,
                TiltStart,
                TiltEnd,
                Zoom,
                ZoomStart,
                ZoomEnd,
                TransitionStart,
                TransitionEnd
            };

            class EmscriptenCameraApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenCameraApi(
                    Camera::GlobeCamera::GpsGlobeCameraController& gpsGlobeCameraController,
                    Resources::Interiors::InteriorsCameraController& interiorsCameraController,
                    const Resources::Interiors::InteriorSelectionModel& interiorSelectionModel);

                void OnUpdate(float deltaSeconds);

                bool SetView( 
                    bool animated,
                    double latDegrees, double longDegrees, double altitude, bool modifyPosition,
                    double distance, bool modifyDistance,
                    double headingDegrees, bool modifyHeading,
                    double tiltDegrees, bool modifyTilt,
                    double transitionDurationSeconds, bool hasTransitionDuration,
                    bool jumpIfFarAway,
                    bool allowInterruption
                );

                void SetViewToBounds(
                    const Eegeo::Space::LatLongAltitude& northEast, 
                    const Eegeo::Space::LatLongAltitude& southWest, 
                    bool animated,
                    bool allowInterruption);

                void StopTransition();
                void TryInterruptTransition();

                void CheckToNotifyZoomStart();

                void SetEventCallback(TCameraEventCallback callback);

                float GetDistanceToInterest();
                Eegeo::dv3 GetCameraInterestPoint();
                float GetPitchDegrees();

            private:
                void HandleTransitionStopped();

                void CheckToNotifyPan();
                void CheckToNotifyRotate();
                void CheckToNotifyTilt();
                void CheckToNotifyZoom();

                void NotifyEventCallback(CameraEventType eventType) const;

                Camera::GlobeCamera::GlobeCameraController& GetCurrentGlobeCameraController();
                const Camera::GlobeCamera::GlobeCameraTouchController* GetCurrentCameraTouchController();
                CameraTransitioner& GetCurrentCameraTransitioner();

                Camera::GlobeCamera::GpsGlobeCameraController& m_gpsGlobeCameraController;
                Resources::Interiors::InteriorsCameraController& m_interiorsCameraController;
                const Resources::Interiors::InteriorSelectionModel& m_interiorSelectionModel;
                CameraTransitioner m_cameraTransitioner;
                CameraTransitioner m_interiorCameraTransitioner;
                Helpers::TCallback0<EmscriptenCameraApi> m_transitionStoppedCallback;

                TCameraEventCallback m_eventCallback;

                bool m_shouldNotifyZoom;
                bool m_wasDragging;
                bool m_wasPanning;
                bool m_wasRotating;
                bool m_wasTilting;
                bool m_wasZooming;
                Eegeo::v3 m_previousCameraRightVector;
                float m_previousTiltDegrees;
                float m_previousDistanceToInterest;
            };
        }
    }
}