set(headers ${headers} libs/eegeo/platform/Modules
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Modules FILES ${currsources})
include(libs/eegeo/platform/Modules/Core/CMakeLists.txt)
include(libs/eegeo/platform/Modules/Data/CMakeLists.txt)
include(libs/eegeo/platform/Modules/Map/CMakeLists.txt)
