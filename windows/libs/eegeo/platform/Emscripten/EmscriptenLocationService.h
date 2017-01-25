// Copyright (c) 2014 eeGeo. All rights reserved.

#pragma once

#include "Types.h"
#include "ILocationService.h"

namespace Eegeo
{
    namespace Emscripten
    {
        class EmscriptenLocationService  : public Eegeo::Location::ILocationService, protected Eegeo::NonCopyable
        {
        public:
            const bool GetIsAuthorized() const { return false; };

            bool IsIndoors() { return false; }
            bool GetIndoorID(int& indoorID) { return false; }
			bool GetLocation(Eegeo::Space::LatLong& latlong) { return false;}
            bool GetAltitude(double& altitude) { return false;}
            bool GetFloorIndex(int& floorIndex) { return false; }
            bool GetHorizontalAccuracy(double& accuracy) { return false;}
            bool GetHeadingDegrees(double& headingDegrees) { return false;}
            void StopListening(){};
        };
    }
}