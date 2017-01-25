#pragma once

#include <map>
#include <string>

#include "Graphics.h"
#include "Types.h"
#include "Spinlock.h"

#define Eegeo_LOG_VIDEO_MEMORY_STATS

#if defined(Eegeo_LOG_VIDEO_MEMORY_STATS)
#define Eegeo_TEXTURE_MEMORY_ADD(textureID, internalFormat, width, height, faceCount, isMipped) \
    Eegeo::VideoMemoryMonitor::Get().AddTexture((textureID), Eegeo::VideoMemoryMonitor::EstimateGLTextureSize((internalFormat), (width), (height), (faceCount), (isMipped)))
#define Eegeo_TEXTURE_MEMORY_REMOVE(textureID) \
    Eegeo::VideoMemoryMonitor::Get().RemoveTexture((textureID))

#define Eegeo_BUFFER_MEMORY_ADD(bufferID, bufferSize) \
    Eegeo::VideoMemoryMonitor::Get().AddBuffer((bufferID), (bufferSize))
#define Eegeo_BUFFER_MEMORY_REMOVE(bufferID) \
    Eegeo::VideoMemoryMonitor::Get().RemoveBuffer((bufferID))

#else

#define Eegeo_TEXTURE_MEMORY_ADD(textureID, internalFormat, width, height, faceCount, isMipped)
#define Eegeo_TEXTURE_MEMORY_REMOVE(textureID)

#define Eegeo_BUFFER_MEMORY_ADD(bufferID, bufferSize)
#define Eegeo_BUFFER_MEMORY_REMOVE(bufferID)

#endif

namespace Eegeo
{

    class GLUsageTracker
    {
    public:

        void AddNameWithUsage(uint32_t name, size_t usage)
        {
            SpinLockAutoLock lock(m_lock);
            
            if (m_namesToUsage.find(name) == m_namesToUsage.end())
            {
                m_namesToUsage.insert(std::make_pair(name, usage));
            }
            else
            {
                m_namesToUsage[name] = usage;
            }
        }

        void RemoveName(uint32_t name)
        {
            SpinLockAutoLock lock(m_lock);
            m_namesToUsage.erase(name);
        }

        size_t GetCount() const
        {
            SpinLockAutoLock lock(m_lock);
            return m_namesToUsage.size();
        }

        size_t GetTotal() const
        {
            SpinLockAutoLock lock(m_lock);
            size_t total = 0;

            for (std::map<uint32_t, size_t>::const_iterator it = m_namesToUsage.begin(); it != m_namesToUsage.end(); ++it)
            {
                total += it->second;
            }

            return total;
        }

    private:

        mutable SpinLock m_lock;
        std::map<uint32_t, size_t> m_namesToUsage;
    };

    class VideoMemoryMonitor
    {
    public:

        void AddTexture(uint32_t texture, size_t size);
        void RemoveTexture(uint32_t texture);

        void AddBuffer(uint32_t buffer, size_t size);
        void RemoveBuffer(uint32_t buffer);

        static VideoMemoryMonitor& Get()
        {
            static VideoMemoryMonitor instance;
            return instance;
        }

        std::string GenerateReport();
        
        size_t GetBufferByteCount() const { return m_buffers.GetTotal(); }
        size_t GetBufferCount() const { return m_buffers.GetCount(); }
        size_t GetTextureByteCount() const { return m_textures.GetTotal(); }
        size_t GetTextureCount() const { return m_textures.GetCount(); }

        static size_t EstimateGLTextureSize(int internalFormat, uint32_t width, uint32_t height, uint32_t faceCount, bool isMipped);

    private:

        static size_t GetBitsPerTexelBlock(int internalFormat, int &blockWidthInTexels, int &blockHeightInTexels);

        GLUsageTracker m_textures;
        GLUsageTracker m_buffers;
    };

};
