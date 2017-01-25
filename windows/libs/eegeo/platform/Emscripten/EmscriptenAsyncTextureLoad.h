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
		class EmscriptenAsyncTextureLoad : public Rendering::AsyncTexturing::IAsyncTextureLoad
		{
			Helpers::ITextureFileLoader& m_textureLoader;
			const Helpers::ICallback1<const Eegeo::Rendering::AsyncTexturing::AsyncTextureLoadResult>& m_completionCallback;
			std::string m_fileExtension;
			const std::vector<Byte>* m_pResourceBuffer;
			void* m_pUserData;
			bool m_mipmap;
            bool m_use565Format;
            bool m_flipVertically;
			GLuint m_textureId;
			bool m_cancelled;
			bool m_started;

			EmscriptenAsyncTextureLoad(
				Helpers::ITextureFileLoader& textureLoader,
				const Helpers::ICallback1<const Eegeo::Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
				const std::string& fileExtension,
				const std::vector<Byte>* pResourceBuffer,
				void* pUserData,
				bool mipmap,
                bool use565Format,
                bool flipVertically);

			~EmscriptenAsyncTextureLoad();

			void BeginAsyncTextureDecode();

		public:

			static EmscriptenAsyncTextureLoad& Build(
				Helpers::ITextureFileLoader& textureLoader,
				const Helpers::ICallback1<const Eegeo::Rendering::AsyncTexturing::AsyncTextureLoadResult>& completionCallback,
				const std::string& fileExtension,
				const std::vector<Byte>& resourceBuffer,
				void* pUserData,
				bool mipmap,
                bool use565Format,
                bool flipVertically);

			virtual void Begin();

			virtual void Cancel();

			void HandleTextureDecodingComplete(GLuint textureId, bool success, int width, int height);
		};
	}
}
