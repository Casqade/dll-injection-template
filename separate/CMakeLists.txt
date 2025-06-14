cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

cmake_policy(SET CMP0091 NEW)

set(TARGET DllInjectionTemplate)
project(${TARGET} VERSION 1.0 LANGUAGES CXX ASM_MASM)

if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  message(FATAL_ERROR "Only MSVC compiler is supported")
endif()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

if (NOT ${BUILD_SHARED_LIBS})
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()


add_subdirectory(Loader)
add_subdirectory(Patch)
