// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IWorkPool.h"
#include <deque>

namespace Eegeo
{
    namespace Emscripten
    {
        class EmscriptenMainThreadWorkPool : protected Eegeo::NonCopyable, public Concurrency::Tasks::IWorkPool
        {
        public:
            EmscriptenMainThreadWorkPool();
            ~EmscriptenMainThreadWorkPool();
                
            void Start();
            void Stop();
            void QueueWork(Concurrency::Tasks::WorkItem* workItem);
            void Flush();
            Concurrency::Tasks::TaskWorkPoolState::Values GetState() const;

        private:
            std::deque<Concurrency::Tasks::WorkItem*> m_workItems;
        };
    }
}
