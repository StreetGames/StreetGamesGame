if(${ANDROID})
set(headers ${headers} libs/eegeo/curl/android-armeabi
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\curl\\android-armeabi FILES ${currsources})
endif(${ANDROID})
