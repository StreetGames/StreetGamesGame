set(headers ${headers} libs/eegeo/httpxx
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\httpxx FILES ${currsources})
include(libs/eegeo/httpxx/code/CMakeLists.txt)
include(libs/eegeo/httpxx/toolchain/CMakeLists.txt)
