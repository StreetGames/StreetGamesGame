// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "ITextureFileLoader.h"
#include "Types.h"
#include "Helpers.h"
#include "GLHelpers.h"
#include "IJpegLoader.h"
#include "ICallback.h"
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Emscripten
	{
		using namespace Eegeo::Helpers;

		class EmscriptenTextureFileLoader : public Eegeo::Helpers::ITextureFileLoader, protected Eegeo::NonCopyable
		{
			Eegeo::Helpers::IFileIO* m_pFileIO;
            Eegeo::Helpers::Jpeg::IJpegLoader& m_jpegLoader;

            bool LoadPng(Eegeo::Helpers::GLHelpers::TextureInfo &textureInfo, const std::string& filename, bool mipmap, bool invertVertically);
            
            bool LoadJpg(Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, const std::string& filename, bool mipmap, bool invertVertically);
            
        public:
            EmscriptenTextureFileLoader(Eegeo::Helpers::IFileIO *pFileIO, Eegeo::Helpers::Jpeg::IJpegLoader& jpegLoader);
            virtual ~EmscriptenTextureFileLoader();
            
            virtual bool LoadTexture(Eegeo::Helpers::GLHelpers::TextureInfo& info, const std::string& fileName, bool mipmap = false);

            virtual Rendering::AsyncTexturing::IAsyncTextureLoad& LoadFromFileAsync(
                const ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
                const std::string& fileName,
                void* pUserData,
                bool mipmap=false);

            virtual Rendering::AsyncTexturing::IAsyncTextureLoad& LoadCubeFromFileAsync(
                const ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
                const Helpers::CubeTextureName& textureName,
                void* pUserData);
                        
            virtual bool LoadFromBuffer(
                Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo, 
                const std::string& fileExtension, 
                const Byte* resourceBuffer, 
                size_t bufferSizeBytes, 
                bool mipmap=false);

            virtual Rendering::AsyncTexturing::IAsyncTextureLoad& LoadFromBufferAsync(
                const ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
                const std::string& fileExtension,
                const std::vector<Byte>& resourceBuffer,
                void* pUserData,
                bool mipmap=false);            

            virtual Rendering::AsyncTexturing::IAsyncTextureLoad& LoadCubeFromBuffersAsync(
                const ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
                const std::vector<const std::vector<Byte>*>& cubeFaceBuffers,
                void* pUserData
            );
            
            virtual bool LoadFromCubeFaces(Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo,
                                           const std::vector<const std::vector<Byte>*>& cubeFaceBuffers);
            
            virtual bool LoadFromCubeFaces(Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo,
                                           const CubeFaceFileNames& cubeFaceFileNames);
            
            virtual bool LoadCubeTexture(Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo,
                                         const Helpers::CubeTextureName& textureName);
        };
    }
}
