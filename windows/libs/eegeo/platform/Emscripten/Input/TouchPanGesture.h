// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "AppInterface.h"
#include "VectorMath.h"
#include "IEmscriptenInputHandler.h"
#include "InputEvents.h"
#include <map>

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
			class TouchPanGesture
			{
			private:
				IEmscriptenInputHandler* m_pHandler;
				bool m_panning;
				std::map<long, Eegeo::v2> m_inputMap;

				Eegeo::v2 m_panCenter;
				Eegeo::v2 m_panAnchor;
				float m_majorScreenDimension;

				Eegeo::v2 GetTouchExtents(const TouchInputEvent& event) const;
				void PopulatePanData(int numTouches, const v2& touchExtents, AppInterface::PanData& out_panData) const;

			public:
				TouchPanGesture(IEmscriptenInputHandler* pHandler, const float screenWidth, const float screenHeight);

				void PointerDown(const TouchInputEvent& event);
				void PointerUp(const TouchInputEvent& event);
				void PointerMove(const TouchInputEvent& event);

				void NotifyScreenPropertiesChanged(int screenWidth, int screenHeight);
			};
		}
	}
}
