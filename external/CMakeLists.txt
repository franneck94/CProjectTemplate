set(LOG_LIBRARY "log")
set(LOG_SOURCES "log/src/log.c")
set(LOG_INCLUDES "log/src/")

add_library(${LOG_LIBRARY} STATIC ${LOG_SOURCES})
target_include_directories(${LOG_LIBRARY} PUBLIC ${LOG_INCLUDES})
