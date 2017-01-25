// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IWebRequestService.h"
#include "Web.h"
#include "Tasks.h"
#include "ICallback.h"
#include "CallbackCollection.h"
#include <map>
#include <deque>

namespace Eegeo
{
    namespace Emscripten
    {
        class EmscriptenWebRequestService: public Web::IWebRequestService, protected Eegeo::NonCopyable
        {
        public:
            EmscriptenWebRequestService();
            ~EmscriptenWebRequestService();

            void EnqueueLoad(Web::IWebLoadRequest* pWebRequest);
            void EnqueueCancel(Web::IWebLoadRequest* pWebRequest);

            void Update();

            bool HasOngoingNetworkActivity() const;
            void RegisterNetworkActivityChanged(Helpers::ICallback1<const bool&>& callback);
            void UnregisterNetworkActivityChanged(Helpers::ICallback1<const bool&>& callback);

        private:    
            void ProcessPendingDeletedRequests();
            void CheckNetworkActivityChanged();

            void HandleEmscriptenLoadedEvent(const Web::IWebLoadRequest& webRequest, const Web::TResourceData& bodyData);
            void HandleEmscriptenErrorEvent(const Web::IWebLoadRequest& webRequest, const int& statusCode);         
            
            Helpers::TCallback2<EmscriptenWebRequestService, const Web::IWebLoadRequest, const Web::TResourceData> m_emscriptenOnLoadedHandler;
            Helpers::TCallback2<EmscriptenWebRequestService, const Web::IWebLoadRequest, const int> m_emscriptenOnErrorHandler;
            std::map<const Web::IWebLoadRequest*, int> m_requestToActiveEmscriptenRequestId;
            std::deque<const Web::IWebLoadRequest*> m_requestsToDelete;

            Helpers::CallbackCollection1<const bool&> m_networkActivityChangedCallbacks;
            bool m_hasNetworkActivity;
        };
    }
}