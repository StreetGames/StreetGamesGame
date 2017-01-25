// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "Types.h"
#include "Networking.h"
#include <vector>

namespace Eegeo
{
    namespace Networking
    {
        class ITcpSocket
        {
        public:
            virtual ~ITcpSocket() { }

            virtual u64 GetSocketDescriptor() const = 0;

            virtual void StartListening(int port) = 0;
            virtual ITcpSocket* Accept() = 0;
            virtual void SetNonBlocking() = 0;

            virtual ITcpSocketSet* GetSocketSet() = 0;
            virtual ITcpSocketSet* GetSocketSet(const std::vector<ITcpSocket*>& clientSockets) = 0;

            virtual ssize_t Receive(char* buffer, size_t maxBufferLength) = 0;
            virtual void Send(const char* data, int length) const = 0;

            virtual void Close() = 0;
        };
    }
}