// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

namespace Eegeo
{
    namespace Emscripten
    {
        int LogConsoleMessage(const char * __restrict message);

        int LogConsoleWarn(const char * __restrict message);

        int LogConsoleError(const char * __restrict message);
    }
}


