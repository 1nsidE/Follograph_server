cmake_minimum_required(VERSION 2.8.11)

set(HTTP_SOURCES
FormData.cpp
Http.cpp
HttpClient.cpp
HttpHeader.cpp
HttpRequest.cpp
HttpResponse.cpp
HttpUrl.cpp
)

add_library(httpcpp SHARED ${HTTP_SOURCES}
    $<TARGET_OBJECTS:sockets>
)


include_directories(${GNUTLS_INCLUDE_DIR})

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

    add_definitions(-DHTTP_LIB_EXPORT)
   	target_link_libraries(httpcpp ${GNUTLS_LIBRARIES} "Ws2_32.lib")

elseif(CMAKE_COMPILER_IS_GNUCXX)

	target_link_libraries(httpcpp ${GNUTLS_LIBRARIES})

elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")

	target_link_libraries(httpcpp ${GNUTLS_LIBRARIES})

endif()


message("GnuTLS libraries are " ${GNUTLS_LIBRARIES})
