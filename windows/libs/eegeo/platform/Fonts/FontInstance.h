// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "AsyncTexturing.h"
#include <vector>
#include <string>

namespace Eegeo
{
    namespace Fonts
    {
        class FontInstance : Eegeo::NonCopyable
        {
        public:
            FontInstance(Rendering::AsyncTexturing::IAsyncTextureRequestor& asyncTextureRequestor,
                         const std::string& fontInstanceId,
                         float outlineThickness,
                         float height,
                         float base,
                         float lineHeight,
                         float meanLine,
                         float scaleW,
                         float scaleH,
                         const std::vector<std::string>& textureNames,
                         FontCharacterTable* characterTable,
                         FontKerningTable* kerningTable,
                         bool isSdf,
                         float sdfSpread);

            ~FontInstance();
            
            const std::string& GetId() const { return m_fontInstanceId; }
            float GetBase() const { return m_base; }
            float GetLineHeight() const { return m_lineHeight; }
            float GetMeanLine() const { return m_meanLine; }
            float GetHeight() const { return m_height; }
            int GetNumPages() const { return static_cast<int>(m_textureList.size()); }
            float GetOutlineThickness() const { return m_outlineThickness; }
            float GetScaleW() const { return m_scaleW; }
            float GetScaleH() const { return m_scaleH; }
            bool IsSdf() const { return m_isSdf; }
            float GetSdfSpread() const { return m_sdfSpread; }

            const std::vector<Rendering::AsyncTexturing::IAsyncTexture*>& GetTextureList() const { return m_textureList; }

            const FontCharacter& GetCharacter(u32 charUnicode) const;
            const FontCharacter& GetCharacterOrDefault(u32 charUnicode) const;
            bool ContainsCharacter(u32 charUnicode) const;
            float GetKerning(u32 firstUnicode, u32 secondUnicode) const;

        private:            
            void LoadFontPageTextures(
                Rendering::AsyncTexturing::IAsyncTextureRequestor& asyncTextureRequestor,
                const std::vector<std::string>& textureNames
            );

            const std::string m_fontInstanceId;
            float m_outlineThickness;
            float m_height;
            float m_base;
            float m_lineHeight;
            float m_meanLine;
            float m_scaleW;
            float m_scaleH;
            bool m_isSdf;
            float m_sdfSpread;
            
            std::vector<Rendering::AsyncTexturing::IAsyncTexture*> m_textureList;
            FontCharacterTable* m_characterTable;
            FontKerningTable* m_kerningTable;
        };
    }
}
