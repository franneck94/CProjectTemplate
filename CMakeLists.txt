cmake_minimum_required(VERSION 3.16)

project("CTemplate" VERSION 1.0.0 LANGUAGES C)

# Global CMake variables are set here
set(CMAKE_C_STANDARD              99)
set(CMAKE_C_STANDARD_REQUIRED     ON)
set(CMAKE_C_EXTENSIONS            OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(ENABLE_WARNINGS      "Enable to add warnings to a target."   ON)
option(ENABLE_TESTING       "Enable a Unit Testing build."          ON)
option(ENABLE_COVERAGE      "Enable a Code Coverage build."         OFF)
option(ENABLE_LTO           "Enable to add Link Time Optimization." OFF)
option(ENABLE_CCACHE        "Enable to add Ccache."                 OFF)

# Project/Library Names
set(LIBRARY_NAME    "lib")
set(EXECUTABLE_NAME "main")

### CMAKE MODULES

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(ConfigSafeGuards)
include(Warnings)
include(Docs)
include(AddGitSubmodule)
include(FetchContent)
include(LTO)

if (ENABLE_COVERAGE)
    include(CTest)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif()

if (ENABLE_LTO)
    find_lto(C)
endif()

### EXTERNAL LIBRARIES

add_git_submodule(external/log)

FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.5.2
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(unity)

FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/cofyc/argparse.git
    GIT_TAG v1.1.0
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(argparse)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

### SUB DIRECTORIES

add_subdirectory(configured)
add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(tests)

### INSTALL TARGETS

install(TARGETS ${EXECUTABLE_NAME}
        EXPORT ${LIBRARY_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(TARGETS ${LIBRARY_NAME}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)
