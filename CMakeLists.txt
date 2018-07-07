cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(sample_project)

message("Starting cmake")

add_executable(main main.cpp)

include_directories(sample_library)
add_subdirectory (sample_library)
target_link_libraries(main sample_library)

include_directories(sample_Qt_UI_library)
add_subdirectory (sample_Qt_UI_library)
target_link_libraries(main sample_Qt_UI_library)

include_directories(tral)
add_subdirectory (tral)
target_link_libraries(main tral)

include(toolchain-settings.cmake)