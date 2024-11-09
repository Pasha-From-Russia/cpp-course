cmake_minimum_required(VERSION 3.22)

project(helloworld VERSION 0.0.${BUILD_NUMBER})


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -ggdb")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBUILD_NUMBER=${BUILD_NUMBER}")

project(01.ci_cd_helloworld)

add_executable(helloworld
    src/main.cpp
)

set_target_properties(helloworld PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME helloworld)
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH "${BUILD_NUMBER}")
#set(CPACK_PACKAGING_INSTALL_PREFIX "$ENV{HOME}/otus-cpp/")
set(CPACK_PACKAGE_CONTACT not@available.com)
include(CPack)
