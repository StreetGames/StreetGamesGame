// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "Types.h"
#include "ITcpSocket.h"
#include "ITcpSocketSet.h"

#include <vector>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>


namespace Eegeo
{
    namespace Networking
    {
        namespace Posix
        {
            class PosixTcpSocket: public ITcpSocket, protected Eegeo::NonCopyable
            {
            public:
                static PosixTcpSocket* CreateListenerSocket();

                PosixTcpSocket(int clientSocketDescriptor, sockaddr_in clientSocket);
                ~PosixTcpSocket();

                u64 GetSocketDescriptor() const { return static_cast<u64>(m_socketDescriptor); }

                void StartListening(int port);
                ITcpSocket* Accept();
                void SetNonBlocking();

                ITcpSocketSet* GetSocketSet();
                ITcpSocketSet* GetSocketSet(const std::vector<ITcpSocket*>& clientSockets);

                ssize_t Receive(char* buffer, size_t maxBufferLength);
                void Send(const char* data, int length) const;

                void Close();

            private:

                int m_socketDescriptor;
                sockaddr_in m_socket;
            };
        }
    }
}