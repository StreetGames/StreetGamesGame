// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "TcpClientCallback.h"
#include "ITcpSocket.h"

namespace Eegeo
{
    namespace Networking
    {
        class ITcpClient
        {
        public:
            virtual ~ITcpClient() { }
            
            virtual const ITcpSocket& GetSocket() const = 0;

            virtual bool Read() = 0;
            virtual void Write(const char* data, int length) const = 0;
            virtual void Close() = 0;
            
            virtual void AddReadCallback(ITcpClientDataCallback& readCallback) = 0;
            virtual void RemoveReadCallback(ITcpClientDataCallback& readCallback) = 0;
            virtual void AddCloseCallback(ITcpClientCallback& closeCallback) = 0;
            virtual void RemoveCloseCallback(ITcpClientCallback& closeCallback) = 0;
        };
    }
}