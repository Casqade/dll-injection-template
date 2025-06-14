cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(TARGET Loader)
project(${TARGET} VERSION 1.0 LANGUAGES CXX)


set(INJECTION_TARGET_FILENAME "" CACHE STRING "Injection target filename")
set(INJECTION_TARGET_MD5 "" CACHE STRING "Injection target MD5 value")
set(INJECTED_PATCH_FILENAME "" CACHE STRING "Injected DLL filename")


add_executable(${TARGET} WIN32)

target_sources(${TARGET} PRIVATE
  Loader.cpp
)

target_compile_definitions(${TARGET} PRIVATE
  WIN32_LEAN_AND_MEAN
  INJECTION_TARGET_FILENAME="${INJECTION_TARGET_FILENAME}"
  INJECTION_TARGET_MD5="${INJECTION_TARGET_MD5}"
  INJECTED_PATCH_FILENAME="${INJECTED_PATCH_FILENAME}"
)

target_link_libraries(${TARGET} PRIVATE
  Crypt32
)

set_target_properties(${TARGET} PROPERTIES
  WIN32_EXECUTABLE TRUE
)
