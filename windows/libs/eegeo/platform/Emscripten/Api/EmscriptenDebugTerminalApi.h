#pragma once

#include "CommandBuffer.h"
#include <string>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            class EmscriptenDebugTerminalApi: protected Eegeo::NonCopyable
            {
            public:
                EmscriptenDebugTerminalApi(Debug::Commands::CommandBuffer& commandBuffer);

                void ExecuteDebugCommand(const std::string& debugCommand) const;

            private:
                Debug::Commands::CommandBuffer& m_commandBuffer;
            };
        }
    }
}