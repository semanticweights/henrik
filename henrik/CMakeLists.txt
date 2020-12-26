cmake_minimum_required(VERSION 3.13.4)
project(henrik)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

set(LINK_LIBS
  open_spiel_core
  games
  game_transforms
  bridge_double_dummy_solver
  algorithms
  utils
)

include_directories(${CMAKE_SOURCE_DIR} libs/open_spiel)
add_subdirectory(libs/open_spiel/open_spiel)

add_executable(abstraction src/abstraction.cpp)
target_link_libraries(abstraction ${LINK_LIBS})
