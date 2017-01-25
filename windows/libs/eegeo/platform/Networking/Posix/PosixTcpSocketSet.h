// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "ITcpSocketSet.h"
#include "Networking.h"
#include <sys/select.h>
#include <sys/time.h>

namespace Eegeo
{
    namespace Networking
    {
        class PosixTcpSocketSet: public ITcpSocketSet
        {
        public:
            PosixTcpSocketSet();

            void Set(const ITcpSocket& socket);
            bool IsSet(const ITcpSocket& socket);
            int Select(time_t timeoutSeconds, long timeoutMicroseconds);

        private:
            int maxFileDescriptorPlusOne;
            fd_set m_fd_set;
        };
    }
}