// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Labels.h"

#include "ICallback.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Labels
    {
        // todo move to Resources namespace
        
        template<typename TResourceType>
        class IResourceObserver
        {
        public:
            typedef const TResourceType CallbackParamType;
            typedef Helpers::ICallback1<CallbackParamType> CallbackType;
            
            virtual ~IResourceObserver() {;}
            
            virtual void RegisterAddedToSceneGraphCallback(CallbackType& callback) = 0;
            virtual void UnregisterAddedToSceneGraphCallback(CallbackType& callback) = 0;
            
            virtual void RegisterRemovedFromSceneGraphCallback(CallbackType& callback) = 0;
            virtual void UnregisterRemovedFromSceneGraphCallback(CallbackType& callback) = 0;
            
            virtual void RegisterResourceDeletedCallback(CallbackType& callback) = 0;
            virtual void UnregisterResourceDeletedCallback(CallbackType& callback) = 0;
            
            virtual void NotifyAddedToSceneGraph(CallbackParamType& resource) = 0;
            virtual void NotifyRemovedFromSceneGraph(CallbackParamType& resource) = 0;
            virtual void NotifyResourceDeleted(CallbackParamType& resource) = 0;
        };
    }
}