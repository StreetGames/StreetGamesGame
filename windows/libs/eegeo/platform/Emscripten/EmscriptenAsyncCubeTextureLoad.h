// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "IAsyncTextureLoad.h"
#include "Helpers.h"
#include "Types.h"
#include "GLHelpers.h"
#include "ICallback.h"
#include "AsyncTexturing.h"
#include <string>
#include <vector>

namespace Eegeo
{
	namespace Emscripten
	{
		class EmscriptenAsyncCubeTextureLoad : public Rendering::AsyncTexturing::IAsyncTextureLoad
		{
			Helpers::ITextureFileLoader& m_textureLoader;
			const Helpers::ICallback1<const Eegeo::Rendering::AsyncTexturing::AsyncTextureLoadResult>& m_completionCallback;
			std::vector<const std::vector<Byte>*> m_cubeFaceBuffers;
			void* m_pUserData;
			GLuint m_textureId;
			bool m_cancelled;
			bool m_started;

			EmscriptenAsyncCubeTextureLoad(
				Helpers::ITextureFileLoader& textureLoader,
		        const Helpers::ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
		        const std::vector<const std::vector<Byte>*>& cubeFaceBuffers,
		        void* pUserData);

			~EmscriptenAsyncCubeTextureLoad();
			
		public:

		    static EmscriptenAsyncCubeTextureLoad& Build(
				Helpers::ITextureFileLoader& textureLoader,
		        const Helpers::ICallback1<const Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
		        const std::vector<const std::vector<Byte>*>& cubeFaceBuffers,
		        void* pUserData);

			virtual void Begin();

			virtual void Cancel();

			void BeginAsyncTextureDecode();

			void HandleTextureDecodingComplete(GLuint textureId, bool success, int width, int height);
		};
	}
}
