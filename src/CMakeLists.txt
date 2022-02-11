add_subdirectory(model/entities)
add_subdirectory(model/intents)
add_subdirectory(processor)
add_subdirectory(service)

include(FetchContent)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG        v1.x
)
FetchContent_MakeAvailable(spdLog)

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
    main.cpp)

add_executable(eir ${TARGET_SOURCES})

target_link_libraries(
  eir
  PRIVATE
  nlohmann_json::nlohmann_json)

target_link_libraries (
  eir
  LINK_PUBLIC entities
              intents
              processor
              service)

target_link_libraries(
  eir
  PRIVATE fmt::fmt
          spdlog::spdlog)
