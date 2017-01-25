// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IModelRepository.h"
#include "IModelRepositoryObserver.h"

#include <vector>
#include <map>
#include <algorithm>

namespace Eegeo
{
    namespace Labels
    {
        template <typename TKey, typename TValue>
        class ModelRepository : public virtual IModelRepository<TKey, TValue, typename std::map<TKey, TValue>::const_iterator>, private Eegeo::NonCopyable
        {
        private:
            typedef ModelRepository<TKey, TValue> ThisType;
            typedef std::map<TKey, TValue> TStore;
            
        public:
            typedef typename ThisType::KeyType KeyType;
            typedef typename ThisType::ItemType ItemType;
            typedef typename ThisType::ObserverType ObserverType;
            typedef typename ThisType::IteratorType IteratorType;

            int Size() const
            {
                return static_cast<int>(m_store.size());
            }
            
            bool Contains(const KeyType& key) const
            {
                return m_store.find(key) != m_store.end();
            }
            
            TValue Get(const KeyType& key) const
            {
                Eegeo_ASSERT(Contains(key));
                
                return m_store.at(key);
            }
            
            void Add(const KeyType& key, const ItemType& value)
            {
                Eegeo_ASSERT(!Contains(key));
                
                m_store.insert(std::make_pair(key, value));
                NotifyItemAdded(value);
            }
            
            void Remove(const KeyType& key)
            {
                const ItemType& item = Get(key);
                m_store.erase(key);
                NotifyItemRemoved(item);
            }
            
            void Clear()
            {
                m_store.clear();
            }
            
            void AllKeys(std::vector<KeyType>& out_allKeys) const
            {
                out_allKeys.clear();
                out_allKeys.reserve(m_store.size());
                
                for (typename TStore::const_iterator iter = m_store.begin(); iter != m_store.end(); ++iter)
                {
                    out_allKeys.push_back(iter->first);
                }
            }
            
            
            void AllItems(std::vector<ItemType>& out_allItems) const
            {
                out_allItems.clear();
                out_allItems.reserve(m_store.size());
                
                for (typename TStore::const_iterator iter = m_store.begin(); iter != m_store.end(); ++iter)
                {
                    out_allItems.push_back(iter->second);
                }
            }
            
            IteratorType Begin() const
            {
                return m_store.begin();
            }
            
            IteratorType End() const
            {
                return m_store.end();
            }
            
            void AddObserver(ObserverType& observer)
            {
                m_observers.push_back(&observer);
            }
            
            void RemoveObserver(ObserverType& observer)
            {
                m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), &observer));
            }
        private:
            typedef std::vector<ObserverType*> TObservers;
            
            void NotifyItemAdded(const ItemType& item) const
            {
                for(typename TObservers::const_iterator iter = m_observers.begin(); iter != m_observers.end(); ++iter)
                {
                    (*iter)->OnItemAdded(item);
                }
            }
            
            void NotifyItemRemoved(const ItemType& item) const
            {
                for(typename TObservers::const_iterator iter = m_observers.begin(); iter != m_observers.end(); ++iter)
                {
                    (*iter)->OnItemRemoved(item);
                }
            }
            
            TStore m_store;
            TObservers m_observers;
        };
        
    }
}