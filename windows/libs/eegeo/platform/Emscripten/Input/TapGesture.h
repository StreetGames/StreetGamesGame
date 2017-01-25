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
			class TapGesture
			{
			private:
				int m_tapDownCount;
				int m_tapUpCount;
				int m_currentPointerTrackingStack;
				float m_tapAnchorX;
				float m_tapAnchorY;
				long long m_tapUnixTime;

				IEmscriptenInputHandler* m_pTapHandler;

				void DispatchSingleTap();
				void DispatchDoubleTap();
				bool WithinAnchorDeadzone(const MouseInputEvent& event) const;
				bool IsTapping() const;
				void Reset();
				void TrackPointerDown();
				void TrackPointerUp();
				bool NoPointerDown() const;

			public:
				TapGesture(IEmscriptenInputHandler* pTapHandler);

				void PointerDown(const MouseInputEvent& event);
				void PointerUp(const MouseInputEvent& event);
				void PointerMove(const MouseInputEvent& event);

				void Update(float deltaSeconds);
			};
		}
	}
}
