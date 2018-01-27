cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
project(sample_library VERSION 0.0 DESCRIPTION "sample library")

set(SOURCE_LIB SampleLibrary.cpp)
add_library(sample_library STATIC ${SOURCE_LIB})