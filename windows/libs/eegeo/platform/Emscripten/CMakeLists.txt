set(headers ${headers} libs/eegeo/platform/Emscripten
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Emscripten FILES ${currsources})
include(libs/eegeo/platform/Emscripten/Api/CMakeLists.txt)
include(libs/eegeo/platform/Emscripten/Debug/CMakeLists.txt)
include(libs/eegeo/platform/Emscripten/Input/CMakeLists.txt)
