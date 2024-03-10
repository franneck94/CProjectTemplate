set(APP_SOURCES "main.c")
set(LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

add_executable("main" ${APP_SOURCES})
target_include_directories("main" PUBLIC ${LIBRARY_INCLUDES})

target_link_libraries(
    "main"
    PUBLIC "LibFoo"
           "LibBar"
           log
           argparse)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        "main"
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        "main"
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target("main")
endif()
