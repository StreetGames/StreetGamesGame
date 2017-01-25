// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

#include <vector>
#include <map>

namespace Eegeo
{
    namespace Labels
    {
        template <typename TRepository>
        class IModelRepositoryObserver;
        
        template <typename TKey, typename TValue, typename TIterator>
        class IModelRepository
        {
        public:
            typedef IModelRepository<TKey, TValue, TIterator> ThisType;
            typedef TKey KeyType;
            typedef TValue ItemType;
            typedef TIterator IteratorType;
            typedef IModelRepositoryObserver<ThisType> ObserverType;
        public:
            virtual ~IModelRepository() {;}
            
            virtual int Size() const = 0;
            
            virtual bool Contains(const KeyType& key) const = 0;
            
            virtual ItemType Get(const KeyType& key) const = 0;
            
            virtual void Add(const KeyType& key, const ItemType& value) = 0;
            
            virtual void Remove(const KeyType& key) = 0;
            
            virtual void Clear() = 0;
            
            virtual void AllKeys(std::vector<KeyType>& out_allKeys) const = 0;
            
            virtual void AllItems(std::vector<ItemType>& out_allItems) const = 0;
            
            virtual IteratorType Begin() const = 0;
            
            virtual IteratorType End() const = 0;
            
            virtual void AddObserver(ObserverType& observer) = 0;
            
            virtual void RemoveObserver(ObserverType& observer) = 0;
        };
    }
}