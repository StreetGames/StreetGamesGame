// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "GLHelpers.h"
#include "Types.h"
#include "Rendering.h"
#include "IJpegLoader.h"
#include "JpegImage.h"

namespace Eegeo
{
    namespace Emscripten
    {
        class EmscriptenDummyJpegLoader: public Helpers::Jpeg::IJpegLoader
        {
        public:
            void DecompressJpeg(Byte* jpeg, size_t len, Helpers::Jpeg::JpegImage& image, bool invertVertically=false)
            {
                Eegeo_ASSERT(false, "IJpegLoader not supported on Emscripten - use an asynchronous JPEG load instead");
            }

            bool TryDecompressJpeg(Byte* jpeg, size_t len, Helpers::Jpeg::JpegImage& image, bool invertVertically=false)
            {
                Eegeo_ASSERT(false, "IJpegLoader not supported on Emscripten - use an asynchronous JPEG load instead");
                return false;
            }

            bool LoadJpgFromBuffer(
                Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo,
                const Byte* resourceBuffer,
                size_t resourceBufferSizeBytes,
                bool mipmap,
                bool invertVertically)
            {
                Eegeo_ASSERT(false, "IJpegLoader not supported on Emscripten - use an asynchronous JPEG load instead");
                return false;
            }
        };
    }
}