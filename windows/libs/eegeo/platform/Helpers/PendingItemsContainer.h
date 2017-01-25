// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include <set>

namespace Eegeo
{
    namespace Helpers
    {
        template <typename TItemType>
        class PendingItemsContainer
        {
        protected:
            typedef std::set<TItemType*> TContainer;
            typedef typename TContainer::iterator TIterator;
            typedef typename TContainer::size_type TSize;
            
            TContainer m_items;
            
        public:
            ~PendingItemsContainer()
            {
                CancelAndRemoveAllItems();
            }
            
            void InsertItem(TItemType& item)
            {
                std::pair<TIterator, bool> result = m_items.insert(&item);
                Eegeo_ASSERT(result.second, "Failed to insert item into PendingItemsContainer.\n");
            }
            
            void RemoveItem(TItemType& item)
            {
                size_t numRemoved = m_items.erase(&item);
                Eegeo_ASSERT(numRemoved == 1, "Failed to remove item from PendingItemsContainer.\n");
            }
            
            void CancelAndRemoveAllItems()
            {
                for(TIterator it = m_items.begin(); it != m_items.end(); ++ it)
                {
                    TItemType& item = **it;
                    item.Cancel();
                }
                
                m_items.clear();
            }

            TSize Size() const
            {
                return m_items.size();
            }
        };
    }
}
