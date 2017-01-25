// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "IAsyncBufferTextureRequestor.h"
#include "Helpers.h"
#include "AsyncTexturing.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Emscripten
    {
        class EmscriptenRasterTerrainTextureLoader : protected Eegeo::NonCopyable, public Rendering::AsyncTexturing::IAsyncBufferTextureRequestor
        {
        public:
            EmscriptenRasterTerrainTextureLoader(
                Eegeo::Helpers::ITextureFileLoader& textureFileLoader,
                Rendering::AsyncTexturing::IAsyncTexture& placeholderTexture
            );

            ~EmscriptenRasterTerrainTextureLoader();

            Rendering::AsyncTexturing::IAsyncTexture& RequestTextureFromBuffer(
                std::vector<Byte>& buffer,
                const std::string& textureName,
                const std::string& fileExtension,
                bool generateMipmaps=false);
            
        private:
            Eegeo::Helpers::ITextureFileLoader& m_textureFileLoader;
            Rendering::AsyncTexturing::IAsyncTexture& m_placeholderTexture;
        };
    }
}