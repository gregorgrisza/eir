
set(TARGET_SOURCES
    IntentRecognitionService.hpp
    IntentRecognitionService.cpp)

add_library(service
            ${TARGET_SOURCES})

target_link_libraries(
    service
    LINK_PUBLIC processor
                entities
                intents)

target_include_directories (
    service
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})