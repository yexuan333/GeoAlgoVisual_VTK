cmake_minimum_required(VERSION 3.15)
message("..................")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set_property (GLOBAL PROPERTY AUTOMOC_SOURCE_GROUP "/Generated Files/Moc")
set_property (GLOBAL PROPERTY AUTORCC_SOURCE_GROUP "/Generated Files/Resources")
set_property (GLOBAL PROPERTY AUTOUIC_SOURCE_GROUP "/Generated Files/UIC")
set_property (GLOBAL PROPERTY AUTOGEN_SOURCE_GROUP "/Generated Files/GEN")

FILE(GLOB SRC_FILES "src/*.cpp" "src/*.h" "src/*.ui")
add_executable(VTK_Viewer WIN32 ${SRC_FILES})

# VTK------------------------------------------------------------------------------------------------------------
find_package(VTK COMPONENTS 
CommonColor
CommonCore
FiltersSources
InteractionStyle
RenderingContextOpenGL2
RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
  GUISupportQt
  RenderingQt
  )
  if(NOT VTK_FOUND)
  message(FATAL_ERROR "Unable to find the VTK build folder.")
  endif()
  
  if(NOT(TARGET VTK::GUISupportQt))
  message(FATAL_ERROR "VTK not built with Qt support.")
  endif()
  message (STATUS "VTK_VERSION: ${VTK_VERSION}, Qt Version: ${Qt${VTK_QT_VERSION}Widgets_VERSION}")
  
  
  # QT-------------------------------------------------------------------------------------------------------------
  list(APPEND CMAKE_PREFIX_PATH ${QT_Dir}) # Qt Kit Dir
  set(VTK_QT_VERSION 6)
  find_package(Qt6 QUIET REQUIRED COMPONENTS  Core Gui Widgets OpenGLWidgets REQUIRED) # Qt COMPONENTS
  
  #预编译头文件
  target_precompile_headers(VTK_Viewer PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/src/Stdafx.h)
  
  target_include_directories(VTK_Viewer PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/GeoAlgo/src/
  )
  
  # target_link_directories(VTK_Viewer PUBLIC
  # ${CMAKE_BINARY_DIR}/WeldRecognition/
  # )

target_link_libraries(VTK_Viewer PUBLIC
Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGLWidgets
${VTK_LIBRARIES}
GeoAlgo)

# target_link_libraries(VTK_Viewer ${VTK_LIBRARIES} ${qt_modules})
# vtk_module_autoinit is needed
vtk_module_autoinit(
  TARGETS VTK_Viewer
  MODULES ${VTK_LIBRARIES}
)