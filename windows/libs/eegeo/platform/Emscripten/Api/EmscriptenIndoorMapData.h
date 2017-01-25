#pragma once

#include <string>
#include <vector>

namespace Eegeo
{
    namespace Emscripten
    {
        namespace Api
        {
            struct EmscriptenIndoorMapFloorData
            {
                std::string floorId;
                std::string floorName;
                int floorNumber;
            };
            
            struct EmscriptenIndoorMapData
            {
                std::string indoorMapId;
                std::string indoorMapName;
                std::string sourceVendor;
                int floorCount;
                std::vector<EmscriptenIndoorMapFloorData> floors;
            };
        }
    }
}