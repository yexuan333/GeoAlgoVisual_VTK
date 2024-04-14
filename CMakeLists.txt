cmake_minimum_required(VERSION 3.23) # CMake install : https://cmake.org/download/

if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/env.cmake)
    include(${CMAKE_CURRENT_SOURCE_DIR}/env.cmake)
    message(STATUS QT_Dir: ${QT_Dir})
    message(STATUS VCPKG_Path: ${VCPKG_Path})
else()
  message(FATAL_ERROR "Plaease Make env.cmake")
endif()

# list(APPEND CMAKE_PREFIX_PATH ${VCPKG_Path})
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_Path}/scripts/buildsystems/vcpkg.cmake")

# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("/bigobj")  # 添加 /bigobj 编译选项
add_definitions(-D_WINDOWS)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 优先config查找
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/runtime)

project(GeoAlgoVisual_VTK)

# cpp
add_subdirectory(${CMAKE_SOURCE_DIR}/GeoAlgo)
add_subdirectory(${CMAKE_SOURCE_DIR}/VTK_Viewer)
