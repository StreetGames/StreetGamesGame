// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "VectorMath.h"
#include "InputEvents.h"
#include "IEmscriptenInputHandler.h"

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
			class RotateGesture
			{
			private:
				IEmscriptenInputHandler* pHandler;

				bool m_rotating;

                v2 m_anchor;
				float m_totalRotation;
			public:
				RotateGesture(IEmscriptenInputHandler* pHandler);

				void PointerDown(const MouseInputEvent& event);
				void PointerUp(const MouseInputEvent& event);
				void PointerMove(const MouseInputEvent& event);
			};
		}
	}
}
