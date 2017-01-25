#pragma once

#include "Types.h"
#include "EmscriptenInputProcessor.h"

#include <emscripten/html5.h>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Input
        {
            class EmscriptenInputReceiver: Eegeo::NonCopyable
            {
            public:
                EmscriptenInputReceiver(EmscriptenInputProcessor& inputProcessor, int canvasWidth, int canvasHeight);

                void Update(float deltaTimeSeconds);

                bool MouseCallback(int eventType, const EmscriptenMouseEvent* e, void* userData);
                bool MouseWheelCallback(int eventType, const EmscriptenWheelEvent* e, void* userData);
                bool KeyboardCallback(int eventType, const EmscriptenKeyboardEvent* e, void* userData);
                bool TouchCallback(int eventType, const EmscriptenTouchEvent* e, void* userData);

                void UpdateResolution(int canvasWidth, int canvasHeight);

            private:
                bool PointInCanvas(long x, long y) const;

                EmscriptenInputProcessor& m_inputProcessor;
                int m_canvasWidth;
                int m_canvasHeight;
                bool m_dragStartedInsideMap;
            };
        }
    }
}