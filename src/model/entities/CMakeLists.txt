
set(TARGET_SOURCES
    City.hpp
    City.cpp
    Date.hpp
    Date.cpp
    EntityBuilderProxy.hpp
    EntityBuilderProxy.cpp
    Entity.hpp
    Entity.cpp)

add_library(entities
            ${TARGET_SOURCES})

target_include_directories (entities PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
