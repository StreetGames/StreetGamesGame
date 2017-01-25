set(headers ${headers} libs/eegeo/platform/Modules/Map
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Modules\\Map FILES ${currsources})
include(libs/eegeo/platform/Modules/Map/Layers/CMakeLists.txt)
