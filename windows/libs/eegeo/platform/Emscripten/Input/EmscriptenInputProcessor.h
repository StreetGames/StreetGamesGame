// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IEmscriptenInputHandler.h"
#include "PanGesture.h"
#include "RotateGesture.h"
#include "ZoomGesture.h"
#include "TiltGesture.h"
#include "TouchGesture.h"
#include "TapGesture.h"
#include "TouchPanGesture.h"
#include "TouchRotateGesture.h"
#include "TouchPinchGesture.h"
#include "InputEvents.h"

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
            struct EmscriptenInputProcessorConfig
            {
                EmscriptenInputProcessorConfig()
                    : PanStartThresholdPixels(0.f)
                    , ZoomSensitivity(0.f)
                    , MaxZoomDelta(0.f)
                {}

                float PanStartThresholdPixels;
                float ZoomSensitivity;
                float MaxZoomDelta;
            };

			class EmscriptenInputProcessor
			{
			private:
                IEmscriptenInputHandler* m_pHandler;
                float m_screenWidth;
                float m_screenHeight;

				PanGesture m_pan;
				ZoomGesture m_zoom;
				RotateGesture m_rotate;
				TiltGesture m_tilt;
				TouchGesture m_touch;
				TapGesture m_tap;

                TouchPanGesture m_touchPan;
                TouchRotateGesture m_touchRotate;
                TouchPinchGesture m_touchPinch;

			public:
                static u32 MakeKeyboardModifiers(bool altDown, bool shiftDown, bool controlDown);

				EmscriptenInputProcessor(IEmscriptenInputHandler* pHandler, const float screenWidth, const float screenHeight, const EmscriptenInputProcessorConfig& config);

				void HandleInput(const MouseInputEvent& event);
                void HandleInput(const KeyboardInputEvent& keyEvent);
                void HandleInput(const TouchInputEvent& touchEvent);
				void Update(float deltaSeconds);

				bool IsMouseInsideWindow();
				void SetAllInputEventsToPointerUp(int x, int y);

                inline static EmscriptenInputProcessorConfig DefaultConfig();

                static MouseInputEvent MakeMouseInputEvent(MouseInputAction mouseInputAction, u32 modifiers, float pointerX, float pointerY, float wheelDelta);

                void NotifyScreenPropertiesChanged(int screenWidth, int screenHeight);
			};

            inline EmscriptenInputProcessorConfig EmscriptenInputProcessor::DefaultConfig()
            {
                EmscriptenInputProcessorConfig config;
                config.PanStartThresholdPixels = 4.f;
                config.ZoomSensitivity = 0.02f;
                config.MaxZoomDelta = 50.0f;
                return config;
            }
		}
	}
}
