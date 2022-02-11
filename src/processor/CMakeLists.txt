
include(FetchContent)

FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz
)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_MakeAvailable(json)

set(TARGET_SOURCES
    IntentDefinition.hpp
    IntentDefinition.cpp
    Preprocessor.hpp
    Preprocessor.cpp
    Analyzer.hpp
    Analyzer.cpp
    Reader.hpp
    Reader.cpp)

add_library(processor
            ${TARGET_SOURCES})

target_include_directories (processor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(processor PRIVATE nlohmann_json::nlohmann_json)
