// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IEmscriptenInputHandler.h"
#include "InputEvents.h"

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
			class TouchPinchGesture
			{
			private:
				IEmscriptenInputHandler* m_pHandler;
				bool m_pinching;
				float m_previousDistance;
				float m_majorScreenDimension;

				bool UpdatePinching(bool pinching, const TouchInputEvent& event, float& pinchScale, int numTouches, bool pointerUp);

			public:
				TouchPinchGesture(IEmscriptenInputHandler* pHandler, const float screenWidth, const float screenHeight);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);

				void NotifyScreenPropertiesChanged(int screenWidth, int screenHeight);
			};
		}
	}
}
