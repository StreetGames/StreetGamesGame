if(${WINDOWS})
set(headers ${headers} libs/eegeo/curl/Windows-x86
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\curl\\Windows-x86 FILES ${currsources})
endif(${WINDOWS})
