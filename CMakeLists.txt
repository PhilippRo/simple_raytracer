cmake_minimum_required (VERSION 3.3.2)
project (simple_raytracer)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

file(GLOB SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

message(STATUS "SOURCE_FILES ${SRC_FILES}")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(simple_raytracer ${SRC_FILES})

find_package(SFML 2.4 COMPONENTS graphics audio network window system REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(simple_raytracer ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
else()
    message(ERROR "Unable to Find SFML 2.4")
endif()
