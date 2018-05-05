
set (MY_CXX_FLAGS  "-Wall -Werror -fmessage-length=0")

# Verbose build
#set (MY_CXX_FLAGS "${MY_CXX_FLAGS} -v")

if (CMAKE_COMPILER_IS_GNUCXX)
	# Which compilers to use for C and C++ and ASM-ATT
	set (CMAKE_C_COMPILER       gcc)
	set (CMAKE_CXX_COMPILER     g++)
	set (CMAKE_ASM-ATT_COMPILER as )
else ()
	message (WARNING "unknown compiler")
endif ()

set (CMAKE_CXX_FLAGS "${MY_CXX_FLAGS}")
set (CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-reorder-blocks -fno-schedule-insns -fno-inline")
set (CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -mwindows")


# Helpers---
# CMake can fails turning on C++17 in some environments.
function(custom_enable_cxx17 TARGET)
    # Try to turn on C++17
	target_compile_features(${TARGET} PUBLIC cxx_std_17)
    # Enable C++latest for Visual Studio
	if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "/std:c++latest")
    # Enable libc++, libc++experimental and pthread for Clang
    elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
		set_target_properties(${TARGET} PROPERTIES COMPILE_FLAGS "-stdlib=libc++ -pthread")
        target_link_libraries(${TARGET} c++experimental pthread)
    endif()
endfunction(custom_enable_cxx17)