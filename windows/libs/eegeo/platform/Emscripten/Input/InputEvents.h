// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <vector>

namespace Eegeo
{
	namespace Emscripten
	{
		namespace Input
		{
            enum MouseInputAction
            {
                NoMouseAction = 0,
                MousePrimaryDown,
                MousePrimaryUp,                
                MouseSecondaryDown,
                MouseSecondaryUp,                
                MouseMiddleDown,
                MouseMiddleUp,
                MouseMove,
                MouseWheel
            };

            enum KeyboardModifiers
            {
                KeyboardModifierNone = 0,
                KeyboardModifierAlt = 1,
                KeyboardModifierControl = 2,
                KeyboardModifierShift = 4
            };

            enum TouchInputAction
            {
                NoTouchAction = 0,
                TouchDown,
                TouchUp,
                TouchMove,
                TouchCancel
            };

			struct MouseInputEvent
			{
                MouseInputAction action;
                u32 keyboardModifiers;
                float x;
                float y;
                float z;

				MouseInputEvent(
                    MouseInputAction mouseInputAction,
                    u32 keyboardModifiers,
                    float x,
                    float y, 
                    float z)
				: action(mouseInputAction)
                , keyboardModifiers(keyboardModifiers)
                , x(x)
				, y(y)
                , z(z)
				{

				}

                bool IsAltDown() const { return (keyboardModifiers & KeyboardModifierAlt) != 0; }
                bool IsShiftDown() const { return (keyboardModifiers & KeyboardModifierShift) != 0; }
                bool IsControlDown() const { return (keyboardModifiers & KeyboardModifierControl) != 0; }
			};

            struct KeyboardInputEvent
            {
                char keyCode;
                bool keyDownEvent;
            };

            struct TouchInputPoint
            {
                long pointerId;
                float pointerX;
                float pointerY;
                bool changed;
            };

            struct TouchInputEvent
            {
                TouchInputAction action;
                std::vector<TouchInputPoint> touches;

                int GetFirstChangedIndex() const
                {
                    for (int i=0; i<touches.size(); ++i)
                    {
                        if (touches[i].changed)
                        {
                            return i;
                        }
                    }
                    return -1;
                }
            };
		}
	}
}
