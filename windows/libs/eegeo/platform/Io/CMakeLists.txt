set(headers ${headers} libs/eegeo/platform/Io
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Io FILES ${currsources})
include(libs/eegeo/platform/Io/AsyncModels/CMakeLists.txt)
include(libs/eegeo/platform/Io/ChunkedFileFormat/CMakeLists.txt)
include(libs/eegeo/platform/Io/POD/CMakeLists.txt)
