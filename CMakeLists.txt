cmake_minimum_required(VERSION 3.2)
project(foo)

# compiler setup
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W3 /WX")
    set(dialect "")
else ()
    set(warnings "-Wall -Wextra")
    set(dialect "-std=c++14")
endif ()

if(CMAKE_BUILD_TYPE MATCHES "Coverage")
    message(STATUS "Coverage build...")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_BUILD_TYPE Debug FORCE)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${dialect} ${warnings}")

# dependencies
include(GenerateExportHeader)

add_library( catch2 INTERFACE )
target_include_directories( catch2 INTERFACE libs/Catch2/single_include )

# targets
include_directories(include include/foo)
file(GLOB sources src/*.cpp include/*.hpp include/foo/*.hpp)

add_library(foo SHARED ${sources})
set_target_properties(foo PROPERTIES LINKER_LANGUAGE CXX)

generate_export_header(foo EXPORT_FILE_NAME "${CMAKE_BINARY_DIR}/exports/FooExport.h")
target_include_directories(foo PUBLIC ${CMAKE_BINARY_DIR}/exports)

install(TARGETS foo
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/foo DESTINATION include)
install(FILES ${CMAKE_BINARY_DIR}/exports/FooExport.h DESTINATION include/foo)

enable_testing(true)
add_subdirectory(test)
