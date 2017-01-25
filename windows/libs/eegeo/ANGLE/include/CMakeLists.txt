set(headers ${headers} libs/eegeo/ANGLE/include
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\ANGLE\\include FILES ${currsources})
include(libs/eegeo/ANGLE/include/EGL/CMakeLists.txt)
include(libs/eegeo/ANGLE/include/GLES2/CMakeLists.txt)
include(libs/eegeo/ANGLE/include/GLES3/CMakeLists.txt)
include(libs/eegeo/ANGLE/include/KHR/CMakeLists.txt)
