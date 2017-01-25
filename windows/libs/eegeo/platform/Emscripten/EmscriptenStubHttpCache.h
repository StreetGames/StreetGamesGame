// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IHttpCache.h"
#include "Types.h"
#include "Helpers.h"
#include "Cache.h"
#include "CacheModel.h"
#include <string>

namespace Eegeo
{
	namespace Emscripten
	{
		class EmscriptenStubHttpCache : public Eegeo::Helpers::IHttpCache, protected Eegeo::NonCopyable
		{
		public:
			EmscriptenStubHttpCache() { }

			virtual ~EmscriptenStubHttpCache() {}

            virtual void AddToCache(const Eegeo::Web::Cache::CacheRecord& cacheRecordToAdd) {}

            virtual void RemoveFromCache(const std::string& url) {}

            virtual bool TryGetCachedHeaderInfo(
                    const std::string& url,
                    std::string& out_cachedETag,
                    std::string& out_cachedLastModified) { return false; }

            virtual void GetFileNameByUrl(std::string& name, const std::string& url) { name = ""; }
            virtual void SetMaxCacheSize(Helpers::CacheSize_t size) {}
            virtual void ClearCache() {}
            virtual bool IsInCache(const std::string& url) { return false; }
            virtual void FlushInMemoryCacheRepresentation(bool prune) {}
            virtual void ReloadCacheRepresentationFromStorage() {}
            virtual bool LoadLocallyCachedData(const std::string& url, std::vector<Byte>& out_buffer) { return false; }
            virtual bool GetEnabled() { return false; }
            virtual void SetEnabled(bool enabled) {}
		};
	}
}
