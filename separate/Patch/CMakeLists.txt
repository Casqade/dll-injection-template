cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(TARGET Patch)
project(${TARGET} VERSION 1.0 LANGUAGES CXX ASM_MASM)

option(ENABLE_CONSOLE "Create patch console window" OFF)


add_library(${TARGET} MODULE)

target_sources(${TARGET} PRIVATE
  Patch.cpp
  PatchAPI.cpp
)

target_compile_definitions(${TARGET} PRIVATE
  WIN32_LEAN_AND_MEAN
)

if (${ENABLE_CONSOLE})
  target_compile_definitions(${TARGET} PRIVATE
    PATCH_ENABLE_CONSOLE
  )
endif()

target_link_options(${TARGET} PRIVATE
  /NOIMPLIB
  /NOEXP
)
