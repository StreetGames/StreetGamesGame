// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "ITcpListener.h"
#include "ITcpSocket.h"
#include "TcpListenerState.h"
#include "TcpClientCallback.h"
#include "ITcpClient.h"
#include "CallbackCollection.h"

#include <vector>

namespace Eegeo
{
    namespace Networking
    {
        class TcpListener: public ITcpListener, protected Eegeo::NonCopyable
        {
        public:
            TcpListener(ITcpSocket* pListenSocket);
            ~TcpListener();
           
            void StartListening(int port);
            void Update();
            void StopListening();
            
            const TcpListenerState::Values GetState() const;
            int GetPort() const;
            
            void AddClientConnectedCallback(ITcpClientCallback& callback);
            void RemoveClientConnectedCallback(ITcpClientCallback& callback);
            void AddClientDisconnectedCallback(ITcpClientCallback& callback);
            void RemoveClientDisconnectedCallback(ITcpClientCallback& callback);

        private:
            void AcceptNewClient();

            ITcpSocket* m_pListenSocket;
            TcpListenerState::Values m_state;
            int m_port;
            std::vector<ITcpClient*> m_clients;

            Helpers::CallbackCollection1<ITcpClient> m_connectedCallbacks;
            Helpers::CallbackCollection1<ITcpClient> m_disconnectedCallbacks;
        };
    }
}