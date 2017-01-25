#pragma once

namespace Eegeo
{
    struct AllocationSite
    {
        const char* type;
        const char* file;
        int line;

        AllocationSite(const char* _type, const char* _file, int _line);

    };
};