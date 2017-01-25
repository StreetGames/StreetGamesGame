// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"
#include "IEmscriptenInputHandler.h"
#include "InputEvents.h"

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
			class ZoomGesture
			{
			private:
				IEmscriptenInputHandler* m_pZoomHandler;
                const float m_sensitivity;
                const float m_maxZoomDelta;
                float m_zoomAccumulator;

                void TruncateZoomAccumulator();
			public:
				ZoomGesture(IEmscriptenInputHandler* pZoomHandler, float sensitivity, float maxZoomDelta);

				void PointerMove(const MouseInputEvent& event);

                void Update(float dt);
			};
		}
	}
}
