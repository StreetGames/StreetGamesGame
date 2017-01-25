// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "Types.h"

#include "Camera.h"

namespace Eegeo
{
    namespace Labels
    {
        class ILabelController
        {
        public:
            virtual ~ILabelController() {;}
            
            virtual void Update(float deltaTime, const Camera::RenderCamera& renderCamera) = 0;
        };
    }
}