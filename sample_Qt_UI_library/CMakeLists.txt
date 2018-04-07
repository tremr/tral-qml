cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(sample_Qt_UI_library VERSION 0.0 DESCRIPTION "sample Qt UI library")

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies.
#find_package(Qt5Widgets REQUIRED)
find_package(Qt5 REQUIRED Widgets)

set(SOURCE_LIB SampleQtUI.cpp)
add_library(sample_Qt_UI_library STATIC ${SOURCE_LIB})

# Use the Widgets module from Qt 5.
target_link_libraries(sample_Qt_UI_library Qt5::Widgets)

include(../toolchain-settings.cmake)