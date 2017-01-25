// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"
#include "InputEvents.h"
#include "IEmscriptenInputHandler.h"

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
			class TouchGesture
			{
			private:
				IEmscriptenInputHandler* pHandler;

				void CreateTouchEventData(AppInterface::TouchData& data, const MouseInputEvent& event);

			public:
				TouchGesture(IEmscriptenInputHandler* pHandler);

				void PointerDown(const MouseInputEvent& event);
				void PointerUp(const MouseInputEvent& event);
				void PointerMove(const MouseInputEvent& event);
			};
		}
	}
}
