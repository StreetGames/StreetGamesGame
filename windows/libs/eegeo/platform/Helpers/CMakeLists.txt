set(headers ${headers} libs/eegeo/platform/Helpers
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Helpers FILES ${currsources})
include(libs/eegeo/platform/Helpers/DDS/CMakeLists.txt)
include(libs/eegeo/platform/Helpers/Jpeg/CMakeLists.txt)
