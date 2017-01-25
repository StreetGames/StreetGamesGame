// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Labels.h"
#include "Types.h"


namespace Eegeo
{
    namespace Labels
    {
        template <typename TRepository>
        class IModelRepositoryObserver
        {
        public:
            typedef typename TRepository::ItemType ItemType;
            virtual ~IModelRepositoryObserver() {;}
            
            virtual void OnItemAdded(const ItemType& item) = 0;
            
            virtual void OnItemRemoved(const ItemType& item) = 0;
        };
    }
}