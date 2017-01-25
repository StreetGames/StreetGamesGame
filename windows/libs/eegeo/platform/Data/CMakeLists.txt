set(headers ${headers} libs/eegeo/platform/Data
)
set(currsources
)
set(sources ${sources} ${currsources})
source_group(\\platform\\Data FILES ${currsources})
include(libs/eegeo/platform/Data/Geofencing/CMakeLists.txt)
include(libs/eegeo/platform/Data/GeoJSON/CMakeLists.txt)
include(libs/eegeo/platform/Data/Heatmaps/CMakeLists.txt)
include(libs/eegeo/platform/Data/PolyChart/CMakeLists.txt)
include(libs/eegeo/platform/Data/StencilArea/CMakeLists.txt)
