// Copyright eeGeo Ltd (2012-2016), All Rights Reserved

#pragma once

#include "ITcpClient.h"
#include "ITcpSocket.h"
#include "TcpClientCallback.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Networking
    {
        class TcpClient: public ITcpClient, protected Eegeo::NonCopyable
        {
        public:

            TcpClient(ITcpSocket* pClientSocket);
            ~TcpClient();
            
            const ITcpSocket& GetSocket() const;

            bool Read();
            void Write(const char* data, int length) const;
            void Close();
            
            void AddReadCallback(ITcpClientDataCallback& readCallback);
            void RemoveReadCallback(ITcpClientDataCallback& readCallback);
            void AddCloseCallback(ITcpClientCallback& closeCallback);
            void RemoveCloseCallback(ITcpClientCallback& closeCallback);

        private:
            ITcpSocket* m_pClientSocket;

            Helpers::CallbackCollection3<ITcpClient, char*, int> m_readCallbacks;
            Helpers::CallbackCollection1<ITcpClient> m_closeCallbacks;
            
            const static int MaxBuffer = 1024;
            char m_buffer[MaxBuffer];
        };
    }
}