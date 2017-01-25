// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Helpers.h"
#include "TextureNameHelpers.h"
#include <string>
#include <vector>

namespace Eegeo
{
    namespace Helpers
    {
        struct CubeFaceFileNames
        {
            std::string positiveXFileName;
            std::string negativeXFileName;
            std::string positiveYFileName;
            std::string negativeYFileName;
            std::string positiveZFileName;
            std::string negativeZFileName;
            
            std::vector<std::string> ToVector() const
            {
                std::vector<std::string> result;
                result.push_back(positiveXFileName);
                result.push_back(negativeXFileName);
                result.push_back(positiveYFileName);
                result.push_back(negativeYFileName);
                result.push_back(positiveZFileName);
                result.push_back(negativeZFileName);
                return result;
            }
        };

        class CubeTextureName
        {
        public:

            CubeTextureName(const std::string& textureName);
            CubeFaceFileNames GetCubeFaceFileNames() const;
            bool IsSingleFileCubeMap() const;
            std::string GetSingleFileCubeMapFileName() const;
            const std::string& GetTextureName() const;

            static std::string GetCubeTextureNameForPlatform(const std::string& baseName, bool singleFileCubeMapAvailable);
            
        private:

            std::string m_textureName;

            static const std::string SingleFileCubeMapSuffix;
        };

        void ParseToBuffers(Helpers::IFileIO& fileIO, const CubeTextureName& name, std::vector<const std::vector<Byte>*>& buffers);
    }
}
