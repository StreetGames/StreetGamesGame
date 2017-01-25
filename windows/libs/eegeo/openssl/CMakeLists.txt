set(headers ${headers} libs/eegeo/openssl
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\openssl FILES ${currsources})
include(libs/eegeo/openssl/x64/CMakeLists.txt)
include(libs/eegeo/openssl/x86/CMakeLists.txt)
