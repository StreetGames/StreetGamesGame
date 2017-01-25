if(${WINDOWS})
set(headers ${headers} libs/eegeo/curl/Windows-x64
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\curl\\Windows-x64 FILES ${currsources})
endif(${WINDOWS})
