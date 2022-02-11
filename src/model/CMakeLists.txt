
add_subdirectory(entities)
add_subdirectory(intents)

add_library(model)

target_include_directories (model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})