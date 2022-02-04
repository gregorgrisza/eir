# uncomment to enable the gui examples

# sdl
# add_subdirectory(sdl)

# qt
# add_subdirectory(qt)

# fltk test
# add_subdirectory(fltk)

# gtkmm test
# add_subdirectory(gtkmm)

# imgui example
# add_subdirectory(imgui)

# Nana
# add_subdirectory(nana)

# find_package(fmt CONFIG)
# find_package(spdlog CONFIG)
# find_package(docopt CONFIG)

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

add_executable(eir main.cpp)
target_link_libraries(
  eir
  PRIVATE fmt::fmt
          spdlog::spdlog)
