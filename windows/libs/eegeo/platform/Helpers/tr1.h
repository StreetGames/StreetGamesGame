// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

// Todo: this file should eventually be deleted. It existed to bridge C++03/11 support, but C++03
// support has been removed, so we can just directly include the C++11 headers from now on.
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <memory>

namespace Eegeo
{
    template <class T>
    struct unordered_set {
        typedef std::unordered_set<T> type;
    };
    
    template <class K, class V>
    struct unordered_multimap {
        typedef std::unordered_multimap<K,V> type;
    };

    template <class K, class V, class H=std::hash<K>>
    struct unordered_map {
        typedef std::unordered_map<K,V,H> type;
    };
    
    template <class T>
    struct hash {
        typedef std::hash<T> type;
    };
    
    template <class T>
    struct shared_ptr {
        typedef std::shared_ptr<T> type;
    };
}
