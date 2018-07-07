cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(sample_library)

set(SOURCE_LIB SampleLibrary.cpp)
add_library(sample_library STATIC ${SOURCE_LIB})