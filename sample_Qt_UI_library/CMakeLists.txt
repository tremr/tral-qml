cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(sample_Qt_UI_library VERSION 0.0 DESCRIPTION "sample Qt UI library")

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies.
find_package(Qt5 REQUIRED Quick)

set(SOURCE_LIB SampleQtUI.cpp)
qt5_add_resources(RESOURCES qml.qrc)
add_library(sample_Qt_UI_library STATIC ${SOURCE_LIB} ${RESOURCES})

# Use the Widgets module from Qt 5.
target_link_libraries(sample_Qt_UI_library Qt5::Quick)

include(../toolchain-settings.cmake)