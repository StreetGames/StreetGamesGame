// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"
#include "VectorMath.h"
#include "IEmscriptenInputHandler.h"
#include "InputEvents.h"
#include <vector>

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
			class PanGesture
			{
			private:
				IEmscriptenInputHandler* m_pHandler;
                bool m_panButtonDown;
				bool m_panning;
				v2 m_anchor;
                v2 m_current;
				float m_majorScreenDimension;
                const float m_panStartThresholdPixels;

                AppInterface::PanData PopulatePanData() const;
			public:
				PanGesture(IEmscriptenInputHandler* pHandler, const float screenWidth, const float screenHeight, const float panStartThresholdPixels);

				void PointerDown(const MouseInputEvent& event);
				void PointerUp(const MouseInputEvent& event);
				void PointerMove(const MouseInputEvent& event);

				void NotifyScreenPropertiesChanged(int screenWidth, int screenHeight);
			};
		}
	}
}
