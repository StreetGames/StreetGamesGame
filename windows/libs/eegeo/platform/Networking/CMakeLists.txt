set(headers ${headers} libs/eegeo/platform/Networking
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Networking FILES ${currsources})
include(libs/eegeo/platform/Networking/Posix/CMakeLists.txt)
include(libs/eegeo/platform/Networking/Windows/CMakeLists.txt)
