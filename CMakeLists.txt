#Set the minimum version _before_ setting a project, this way CMake knows which is the minimum supported version.
cmake_minimum_required(VERSION 2.8.8)

#Set the project being built.
project(instagram_cpp)

# Prevent in-source build.
if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "InstagramCpp must not be built in the same directory as the sources.")
endif()

set(GNUTLS_USERPROVIDED_PATH "" CACHE PATH "Path to the GnuTLS directory containing library/header files")
set(JSONCPP_USERPROVIDED_PATH "" CACHE PATH "Path to the JSONcpp directory containing library/header files")

# Set the search path prefix for GnuTLS library and include files.
set(CMAKE_PREFIX_PATH ${GNUTLS_USERPROVIDED_PATH})

find_package(GnuTLS REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wpedantic -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -s")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -std=c++1z")
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    message(STATUS "Clang detected, adding compile flags")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wpedantic -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -s")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fPIC -std=c++1z")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(STATUS "MSVC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /LDd /MDd /W4")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /LD /MD -O3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd4251 /wd4710 /EHsc /DEXP_STL")
endif()

if(APPLE)
	set(CMAKE_MACOSX_RPATH TRUE)
endif(APPLE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(sockets)
add_subdirectory(http)
add_subdirectory(instagram)

file(GLOB HTTP_HEADERS ${PROJECT_SOURCE_DIR}/http/inc/*.h ${PROJECT_SOURCE_DIR}/http/src/exceptions/*.h ${PROJECT_SOURCE_DIR}/sockets/inc/*.h )
file(GLOB INSTAGRAM_HEADERS ${PROJECT_SOURCE_DIR}/instagram/inc/*.h ${PROJECT_SOURCE_DIR}/instagram/src/results/inc/*.h)

file(COPY ${HTTP_HEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/lib/http)
file(COPY ${INSTAGRAM_HEADERS} DESTINATION ${PROJECT_SOURCE_DIR}/lib/instagram)
