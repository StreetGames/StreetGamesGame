set(headers ${headers} libs/eegeo/platform/Concurrency
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Concurrency FILES ${currsources})
include(libs/eegeo/platform/Concurrency/Tasks/CMakeLists.txt)
