set(headers ${headers} libs/eegeo/platform/Camera
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Camera FILES ${currsources})
include(libs/eegeo/platform/Camera/GlobeCamera/CMakeLists.txt)
include(libs/eegeo/platform/Camera/SplinePlayback/CMakeLists.txt)
