set(APP_SOURCES "main.c")

add_executable(${EXECUTABLE_NAME} ${APP_SOURCES})

target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME} log argparse)

target_set_warnings(
    TARGET
    ${EXECUTABLE_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

add_tool_to_target(${EXECUTABLE_NAME})

if(${ENABLE_LTO})
    target_enable_lto(${EXECUTABLE_NAME} optimized)
endif()
