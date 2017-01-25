set(headers ${headers} libs/eegeo/ANGLE
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\ANGLE FILES ${currsources})
include(libs/eegeo/ANGLE/include/CMakeLists.txt)
include(libs/eegeo/ANGLE/x64/CMakeLists.txt)
include(libs/eegeo/ANGLE/x86/CMakeLists.txt)
