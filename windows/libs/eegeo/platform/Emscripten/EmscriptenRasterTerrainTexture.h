// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "LocalAsyncTextureBase.h"
#include "AsyncTexturing.h"
#include "ITextureFileLoader.h"
#include "Rendering.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Emscripten
    {
        class EmscriptenRasterTerrainTexture : public Rendering::AsyncTexturing::LocalAsyncTextureBase
        {
        public:
            EmscriptenRasterTerrainTexture(
                Eegeo::Helpers::ITextureFileLoader& textureFileLoader,
                Rendering::AsyncTexturing::IAsyncTexture& initialTexture,
                const std::string& textureName,
                const std::string& fileExtension,
                const std::vector<Byte>& buffer,
                bool generateMipmap);
        };
    }
}