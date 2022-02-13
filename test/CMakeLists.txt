
Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview4
)

FetchContent_MakeAvailable(Catch2)

# find_package(Catch2 REQUIRED)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

add_library(catch_main OBJECT catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2WithMain)
 # target_link_libraries(catch_main PRIVATE project_options)

add_executable(tests recognition.cpp processor.cpp entities.cpp)
target_link_libraries(
    tests
    catch_main
    entities
    intents
    processor
    service)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data/train_data.json ${CMAKE_CURRENT_SOURCE_DIR}/data/reader_test_data.json
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
catch_discover_tests(
  tests
  TEST_PREFIX
  "unittests."
  OUTPUT_DIR
  .
  OUTPUT_PREFIX
  "unittests."
)
