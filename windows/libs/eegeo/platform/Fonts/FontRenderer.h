// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "Fonts.h"
#include "Text.h"
#include "VectorMathDecl.h"
#include "DebugRendering.h"
#include "IRenderableFilter.h"
#include <vector>

namespace Eegeo
{
    namespace Fonts
    {
        class FontRenderer
        {
        public:
            
            FontRenderer (Eegeo::Text::IScreenTextRenderer& screenTextRenderer);
            ~FontRenderer ();
            
            void SetFont(const FontInstance* pFont) { m_pFont = pFont; }
            
            void Print (float x, float y, float z, const char* text, Eegeo::v4* pColor, u32 alignment, float scaling = 1.0f);
            void Print (float x, float y, float z, const char* text, u32 rgba, u32 alignment, float scalingX = 1.0f, float scalingY = 1.0f);
          
            void PrintMultiLine (float x, float y, float z, const char* text, u32 rgba, u32 alignment, float screenHeight, float scalingX = 1.0f, float scalingY = 1.0f);
           
            void PrintMultiLineClipped	(float x, float y, float z, const char* text, u32 rgba, u32 alignment, float minY, float MaxY, float scalingX = 1.0f, float scalingY = 1.0f);
            
            void PrintML (float x, float y, float z, const char *text, Eegeo::v4* pColor, u32 alignment);
            float PrintBox (float x, float y, float z, float width, const char *text, u32 color, u32 alignment, bool bCalcHeightNoDraw, float scalingX = 1.0f, float scalingY = 1.0f);
            
        private:
            int 	FindTextChar 			(const char *text, int start, int length, int ch);
            void 	InternalPrint 			(float x, float y, float z, const char *text, u32 rgba, int count, float spacing, float scaleX, float scaleY);
            
            float GetHorizontalAlign(const char *textUtf8, int length, u32 alignment, float scaleX) const;
            float GetVerticalAlign(u32 alignment, float scaleY) const;
            
            Eegeo::Text::IScreenTextRenderer& m_screenTextRenderer;
            const FontInstance* m_pFont;

            std::vector<u32> m_unicodeCharactersScatch;
        };
        
        inline void FontRenderer::PrintMultiLine(float x, float y, float z, const char* text, u32 rgba, u32 alignment, float screenHeight, float scalingX, float scalingY)
        {
            PrintMultiLineClipped(x, y, z, text, rgba, alignment, 0.0f, screenHeight, scalingX, scalingY);
        }
    }
	
}