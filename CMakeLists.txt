cmake_minimum_required (VERSION 3.3.2)
project (simple_raytracer)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

file(GLOB SRC_FILES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
)

file(GLOB LIBRARY_FILES
    ${CMAKE_SOURCE_DIR}/lib/*.cpp
)

file(GLOB TEST_FILES
    ${CMAKE_SOURCE_DIR}/tests/*.cpp
)

message(STATUS "SOURCE_FILES ${SRC_FILES}")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(simple_raytracer ${SRC_FILES})

add_library(simple_raytracer_lib STATIC ${LIBRARY_FILES})

find_package(SFML 2.4 COMPONENTS graphics audio network window system REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(simple_raytracer ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
else()
    message(ERROR "Unable to Find SFML 2.4")
endif()
target_link_libraries(simple_raytracer stdc++ m)
target_link_libraries(simple_raytracer simple_raytracer_lib)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest/googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest/googletest-download)
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest/googletest-build
                 EXCLUDE_FROM_ALL)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(test_simple_raytracer ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(test_simple_raytracer gtest_main)
target_link_libraries(test_simple_raytracer simple_raytracer_lib)
add_test(NAME test COMMAND test_simple_raytracer)
