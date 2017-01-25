// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "Types.h"
#include "Networking.h"
#include <ctime>

namespace Eegeo
{
    namespace Networking
    {
        class ITcpSocketSet
        {
        public:
            virtual ~ITcpSocketSet() { }

            virtual void Set(const ITcpSocket& socket) = 0;
            virtual bool IsSet(const ITcpSocket& socket) = 0;
            virtual int Select(time_t timeoutSeconds, long timeoutMicroseconds) = 0;
        };
    }
}