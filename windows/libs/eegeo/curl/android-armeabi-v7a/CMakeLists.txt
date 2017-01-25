if(${ANDROID})
set(headers ${headers} libs/eegeo/curl/android-armeabi-v7a
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\curl\\android-armeabi-v7a FILES ${currsources})
endif(${ANDROID})
