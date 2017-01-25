set(headers ${headers} libs/eegeo/curl
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\curl FILES ${currsources})
include(libs/eegeo/curl/android-arm64-v8a/CMakeLists.txt)
include(libs/eegeo/curl/android-armeabi/CMakeLists.txt)
include(libs/eegeo/curl/android-armeabi-v7a/CMakeLists.txt)
include(libs/eegeo/curl/Windows-x64/CMakeLists.txt)
include(libs/eegeo/curl/Windows-x86/CMakeLists.txt)
