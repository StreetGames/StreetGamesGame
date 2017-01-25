// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Interiors.h"
#include "ICallback.h"
#include "Camera.h"
#include "GlobeCamera.h"
#include "LatLongAltitude.h"
#include "Streaming.h"
#include "RenderCamera.h"

namespace Eegeo
{
    namespace Emscripten
    {
        class EmscriptenIndoorMapController
        {
        public:
            EmscriptenIndoorMapController(Resources::Interiors::InteriorSelectionModel& selectionModel,
                                            const Resources::Interiors::InteriorInteractionModel& interiorInteractionModel,
                                            Resources::Interiors::InteriorTransitionModel& interiorTransitionModel,
                                            Resources::Interiors::Markers::InteriorMarkerModelRepository& markerRepository,
                                            Resources::Interiors::InteriorsCameraController& cameraController,
                                            Camera::GlobeCamera::GlobeCameraController& globeCameraController,
                                            Eegeo::Streaming::CameraFrustumStreamingVolume& streamingVolume);
            
            ~EmscriptenIndoorMapController();
            
            void Update(float dt);
            
        private:
            void HandleInteriorSelectionChanged(const Resources::Interiors::InteriorId& interiorId);

            void UpdateProjection(float t);

            Resources::Interiors::InteriorSelectionModel& m_selectionModel;
            const Resources::Interiors::InteriorInteractionModel& m_interiorInteractionModel;
            Resources::Interiors::InteriorTransitionModel& m_interiorTransitionModel;
            Resources::Interiors::Markers::InteriorMarkerModelRepository& m_markerRepository;
            Resources::Interiors::InteriorsCameraController& m_cameraController;
            Camera::GlobeCamera::GlobeCameraController& m_globeCameraController;
            Eegeo::Streaming::CameraFrustumStreamingVolume& m_streamingVolume;
            
            Helpers::TCallback1<EmscriptenIndoorMapController, const Resources::Interiors::InteriorId> m_selectionChangedCallback;
            Space::LatLongAltitude m_interiorFocusOrigin;

            Camera::RenderCamera m_indoorRenderCamera;
            Camera::RenderCamera m_outdoorRenderCamera;
            
            float m_transitionParam;
        };
    }
}