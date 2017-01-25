set(headers ${headers} libs/eegeo/platform/Concurrency/Tasks
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Concurrency\\Tasks FILES ${currsources})
include(libs/eegeo/platform/Concurrency/Tasks/Messages/CMakeLists.txt)
