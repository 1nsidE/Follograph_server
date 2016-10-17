cmake_minimum_required(VERSION 2.8.8)

include_directories(${GNUTLS_INCLUDE_DIR})

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    #if(DEFINED GNUTLS_INCLUDE)
    #    include_directories(${GNUTLS_INCLUDE})
    #endif()
    # Set specific sources for Windows
    file(GLOB SOCKETS_SOURCES_ARCH
        win/*.cpp)
elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    # Set specific sources for MacOSX
    file(GLOB SOCKETS_SOURCES_ARCH
        macosx/*.cpp)    
elseif(CMAKE_COMPILER_IS_GNUCXX)
    # Set specific sources for Linux
    file(GLOB SOCKETS_SOURCES_ARCH
        linux/*.cpp)    
endif()

#Common sources to all platforms
set(SOCKETS_SOURCES
    #none for now :)
)



add_library(sockets OBJECT ${SOCKETS_SOURCES} ${SOCKETS_SOURCES_ARCH})
