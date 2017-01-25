// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "ILocationService.h"
#include "ICallback.h"

namespace Eegeo
{
    namespace Helpers
    {
        namespace CurrentLocationService
        {
            class ICurrentLocationService
            {
            public:
                virtual ~ICurrentLocationService() { }
                
                virtual void SetLocationService(Location::ILocationService& newLocationService) = 0;
                virtual void AddLocationServiceChangedCallback(ICallback0& callback) = 0;
                virtual void RemoveLocationServiceChangedCallback(ICallback0& callback) = 0;
            };
        }
    }
}