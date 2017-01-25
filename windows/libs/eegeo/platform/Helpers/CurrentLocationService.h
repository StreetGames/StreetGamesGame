// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "ICurrentLocationService.h"
#include "ILocationService.h"
#include "ICallback.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace CurrentLocationService
        {
            class CurrentLocationService : public ICurrentLocationService, public Location::ILocationService
            {
            public:
                CurrentLocationService(Location::ILocationService& locationService);
                
                void SetLocationService(Location::ILocationService& newLocationService);
                void AddLocationServiceChangedCallback(ICallback0& callback);
                void RemoveLocationServiceChangedCallback(ICallback0& callback);
                
                const bool GetIsAuthorized() const;
                
                bool IsIndoors();
                bool GetIndoorID(int& indoorID);
                bool GetLocation(Space::LatLong& latlong);
                bool GetAltitude(double& altitude);
                bool GetFloorIndex(int& floorIndex);
                bool GetHorizontalAccuracy(double& accuracy);
                bool GetHeadingDegrees(double& headingDegrees);
                void StopListening();
                
            private:
                Location::ILocationService* m_pLocationService;
                
                CallbackCollection0 m_locationServiceChangedCallbacks;
            };
        }
    }
}