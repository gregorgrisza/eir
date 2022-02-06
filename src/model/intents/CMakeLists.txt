
set(TARGET_SOURCES
    GetWeather.hpp
    GetWeather.cpp
    GetFact.hpp
    GetFact.cpp
    IntentsManager.hpp
    IntentsManager.cpp
    None.hpp
    None.cpp
    Intent.hpp
    Intent.cpp)

add_library(intents
            ${TARGET_SOURCES})

target_include_directories (intents PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
