cmake_minimum_required(VERSION 2.8.11)

add_subdirectory(results)


if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    add_definitions(-DINSTAGRAM_LIB_EXPORT)

    set(CMAKE_PREFIX_PATH ${JSONCPP_USERPROVIDED_PATH})
    find_library(JSON_LIB_NAME NAMES "jsoncpp" "libjson" "libjsoncpp")

    find_path(JSON_INCLUDE_DIR NAMES json/json.h)
    include_directories(${JSON_INCLUDE_DIR})
    if(NOT JSON_INCLUDE_DIR)
        message(FATAL_ERROR "JSON_INCLUDE_DIR variable is not set because the include/json/json.h file has not been found.\
        Please set JSONCPP_USERPROVIDED_PATH to point to a directory containing lib and include dirs.")
    endif(NOT JSON_INCLUDE_DIR)
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
   set(JSON_LIB_NAME "jsoncpp")
elseif(CMAKE_COMPILER_IS_GNUCXX)
   set(JSON_LIB_NAME "jsoncpp")
endif()

message("JsonCPP library path is: " ${JSON_LIB_NAME})

set(INSTAGRAM_SOURCES 
    InstagramClient.cpp
    InstagramParser.cpp
)

add_library(instagramcpp SHARED ${INSTAGRAM_SOURCES}
    $<TARGET_OBJECTS:results>
)

target_link_libraries(instagramcpp httpcpp ${JSON_LIB_NAME})
