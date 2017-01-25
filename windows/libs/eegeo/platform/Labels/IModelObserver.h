// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "Types.h"
#include "ICallback.h"
#include "CallbackCollection.h"

namespace Eegeo
{
    namespace Labels
    {
        class IModelObserver
        {
        public:
            typedef Helpers::ICallback0 CallbackType;
            
            virtual ~IModelObserver() {;}
            
            virtual void RegisterChangedCallback(CallbackType& callback) = 0;

            virtual void UnregisterChangedCallback(CallbackType& callback) = 0;
        protected:
            virtual void NotifyChanged() const = 0;
        };
    }
}