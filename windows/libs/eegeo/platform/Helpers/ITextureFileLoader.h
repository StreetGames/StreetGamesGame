// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Helpers.h"
#include "Types.h"
#include "GLHelpers.h"
#include "ICallback.h"
#include "AsyncTexturing.h"
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Helpers
	{
        class ITextureFileLoader
		{
		public:
			virtual ~ITextureFileLoader() { }

			virtual bool LoadTexture(
                Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo,
                const std::string& fileName,
                bool mipmap=false)=0;

            virtual Rendering::AsyncTexturing::IAsyncTextureLoad& LoadFromFileAsync(
                const ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
                const std::string& fileName,
                void* pUserData,
                bool mipmap=false)=0;

            virtual Rendering::AsyncTexturing::IAsyncTextureLoad& LoadCubeFromFileAsync(
                const ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
                const Helpers::CubeTextureName& textureName,
                void* pUserData)=0;
            
            virtual bool LoadFromBuffer(
                Eegeo::Helpers::GLHelpers::TextureInfo& textureInfo,
                const std::string& fileExtension,
                const Byte* resourceBuffer,
                size_t bufferSizeBytes,
                bool mipmap=false)=0;

            virtual Rendering::AsyncTexturing::IAsyncTextureLoad& LoadFromBufferAsync(
                const ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
                const std::string& fileExtension,
                const std::vector<Byte>& resourceBuffer,
                void* pUserData,
                bool mipmap=false)=0;

            virtual Rendering::AsyncTexturing::IAsyncTextureLoad& LoadCubeFromBuffersAsync(
                const ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
                const std::vector<const std::vector<Byte>*>& cubeFaceBuffers,
                void* pUserData
            )=0;

            virtual bool LoadCubeTexture(
                Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo,
                const CubeTextureName& cubeTextureName) = 0;
            
            virtual bool LoadFromCubeFaces(
                Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo,
                const std::vector<const std::vector<Byte>*>& cubeFaceBuffers)=0;
            
            virtual bool LoadFromCubeFaces(
                Eegeo::Helpers::GLHelpers::TextureInfo& out_textureInfo,
                const CubeFaceFileNames& cubeFaceFileNames)=0;
		};
	}
}