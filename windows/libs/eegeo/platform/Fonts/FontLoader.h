// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "Helpers.h"
#include "AsyncTexturing.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        class FontLoader : protected Eegeo::NonCopyable
        {
        public:
            FontLoader(Eegeo::Helpers::IFileIO& fileIO,
                       Rendering::AsyncTexturing::IAsyncTextureRequestor& textureFileLoader);
            
            //! Loads a text-format BMFont desciptor, generating a FontInstance object from it, and loads referenced textures for the font
            FontInstance* Load(const std::string& fontInstanceId, const std::string& fontFilename);
            
            //! deprecated
            FontInstance* Load(const std::string& fontFilename, bool generateMipMaps);

        private:
			template <typename TReader, typename TResult> 
			void Read(const std::string& fontFilename, TResult& result);

            FontInstance* LoadInternal(const std::string& fontInstanceId, const std::string& fontFilename, bool generateMipMaps);
            
            bool SetupReplacementCharacter(FontCharacterTable& characterTable);
            
            Eegeo::Helpers::IFileIO& m_fileIO;
            Rendering::AsyncTexturing::IAsyncTextureRequestor& m_asyncTextureRequestor;
        };
    }
}