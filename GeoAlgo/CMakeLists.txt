cmake_minimum_required(VERSION 3.15)

FILE(GLOB SRC_FILES "src/*.cpp" "src/*.h")
add_library(GeoAlgo SHARED ${SRC_FILES})
# add_library(GeoAlgo INTERFACE)
target_include_directories(GeoAlgo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

#预编译头文件
# target_precompile_headers(GeoAlgo PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/src/Stdafx.h)

# target_include_directories(GeoAlgoVisual_VTK PUBLIC
# )

# target_link_directories(GeoAlgoVisual_VTK PUBLIC
# )

# target_link_libraries(GeoAlgoVisual_VTK PUBLIC
# )