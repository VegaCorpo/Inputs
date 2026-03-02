cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE src CONFIGURE_DEPENDS "*.cpp")
file(GLOB_RECURSE common_src CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/common/src/*.cpp")

add_library(orbital_inputs SHARED ${src} ${common_src})

target_include_directories(orbital_inputs PRIVATE
    ${IMGUI_GLOBAL_DIR}
    ${CMAKE_SOURCE_DIR}/common/include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(WIN32)
    target_compile_definitions(orbital_inputs PRIVATE NOGDI NOUSER WIN32_LEAN_AND_MEAN)

    set(PROJECT_DIR ${CMAKE_SOURCE_DIR})
    set(BUILD_DIR ${CMAKE_BINARY_DIR})
    set(INPUTS_DIR "${BUILD_DIR}/inputs/${CMAKE_BUILD_TYPE}")

    set(TARGET_DIR "${PROJECT_DIR}")
endif()
