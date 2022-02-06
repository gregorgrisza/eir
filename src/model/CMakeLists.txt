
add_subdirectory(entities)
add_subdirectory(intents)

set(TARGET_SOURCES
    Action.hpp
    Action.cpp)

add_library(model
            ${TARGET_SOURCES})

target_include_directories (model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})