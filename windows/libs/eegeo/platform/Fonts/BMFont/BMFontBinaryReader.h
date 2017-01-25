// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"
#include "BMFont.h"
#include "Fonts.h"
#include <string>

namespace Eegeo
{
    namespace Fonts
    {
        namespace BMFont
        {
            /*!
             *  Parses BMFont HCFF format font descriptors.
             *  See http://www.angelcode.com/products/bmfont/doc/file_format.html
             */
            class BMFontBinaryReader : Eegeo::NonCopyable
            {
            public:
                //! Parses a BMFont font descriptor serialised in HCFF format from an istream
                //! \param stream input stream providing BMFont descriptor
                //! \param fontReaderResult result output structure
                //! \result true if successful
                bool ParseFontFile(std::istream& stream, BMFontReaderResult& fontReaderResult);
            };
        }
    }
}
