// Copyright eeGeo Ltd (2012-2015), All Rights Reserved

#pragma once

#include "IEmscriptenInputHandler.h"
#include "InputEvents.h"

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
			class TiltGesture
			{
			private:
				IEmscriptenInputHandler* m_pHandler;
				bool m_tilting;
                bool m_secondaryButtonInitiated;
				float m_previousMousePositionY;

                void EndTiltGesture();

			public:
				TiltGesture(IEmscriptenInputHandler* pHandler);

				void PointerDown(const MouseInputEvent& event);
				void PointerUp(const MouseInputEvent& event);
				void PointerMove(const MouseInputEvent& event, float screenWidth, float screenHeight);
			};
		}
	}
}
