// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "IEmscriptenInputHandler.h"
#include "InputEvents.h"

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
			class TouchRotateGesture
			{
			private:
				IEmscriptenInputHandler* m_pHandler;
				bool m_rotating;
				Eegeo::v2 m_lastPointer[2];
				float m_lastRotationRadians;
				float m_totalRotation;
				float m_previousRotationDelta;

				bool m_needNewBaseline;

				Eegeo::v2 m_baselineDirection;

				float m_majorScreenDimension;

				bool UpdateRotation(const TouchInputEvent& event, int numTouches, bool pointerUp);

			public:
				TouchRotateGesture(IEmscriptenInputHandler* pHandler, float screenWidth, float screenHeight);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);

				void NotifyScreenPropertiesChanged(int screenWidth, int screenHeight);
			};
		}
	}
}
