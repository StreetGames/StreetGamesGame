// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IResourceObserver.h"

#include "ICallback.h"
#include "CallbackCollection.h"


namespace Eegeo
{
    namespace Labels
    {
        template<typename TResourceType>
        class ResourceObserver : public virtual IResourceObserver<TResourceType>, private Eegeo::NonCopyable
        {
        public:
            typedef IResourceObserver<TResourceType> BaseType;
            typedef typename BaseType::CallbackParamType CallbackParamType;
            typedef typename BaseType::CallbackType CallbackType;
            
            
            void RegisterAddedToSceneGraphCallback(CallbackType& callback)
            {
                m_addedToSceneGraphCallbacks.AddCallback(callback);
            }
            
            void UnregisterAddedToSceneGraphCallback(CallbackType& callback)
            {
                m_addedToSceneGraphCallbacks.RemoveCallback(callback);
            }
            
            void RegisterRemovedFromSceneGraphCallback(CallbackType& callback)
            {
                m_removedFromSceneGraphCallbacks.AddCallback(callback);
            }
            
            void UnregisterRemovedFromSceneGraphCallback(CallbackType& callback)
            {
                m_removedFromSceneGraphCallbacks.RemoveCallback(callback);
            }
            
            void RegisterResourceDeletedCallback(CallbackType& callback)
            {
                m_resourceDeletedCallbacks.AddCallback(callback);
            }
            
            void UnregisterResourceDeletedCallback(CallbackType& callback)
            {
                m_resourceDeletedCallbacks.RemoveCallback(callback);
            }
            
            void NotifyAddedToSceneGraph(CallbackParamType& resource)
            {
                m_addedToSceneGraphCallbacks.ExecuteCallbacks(resource);
            }
            
            void NotifyRemovedFromSceneGraph(CallbackParamType& resource)
            {
                m_removedFromSceneGraphCallbacks.ExecuteCallbacks(resource);
            }
            
            void NotifyResourceDeleted(CallbackParamType& resource)
            {
                m_resourceDeletedCallbacks.ExecuteCallbacks(resource);
            }
        private:
            typedef Helpers::CallbackCollection1<CallbackParamType> TCallbackCollection;
            
            TCallbackCollection m_addedToSceneGraphCallbacks;
            TCallbackCollection m_removedFromSceneGraphCallbacks;
            TCallbackCollection m_resourceDeletedCallbacks;
        };
    }
}