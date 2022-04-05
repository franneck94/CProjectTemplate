set(LOG_SOURCES
    "log/src/log.c")
set(LOG_HEADERS
    "log/src/log.h")
set(LOG_INCLUDES
    "log/src/")
add_library(log STATIC
    ${LOG_SOURCES}
    ${LOG_HEADERS})
target_include_directories(log PUBLIC
    ${LOG_INCLUDES})

if (${ENABLE_WARNINGS})
    target_set_warnings(TARGET log ENABLE OFF AS_ERROR OFF)
endif()
