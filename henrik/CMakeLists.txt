cmake_minimum_required(VERSION 3.13.4)
project(henrik)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED)

# build open_spiel
set(OPEN_SPIEL_LIBRARIES
  open_spiel_core
  games
  game_transforms
  bridge_double_dummy_solver
  algorithms
  utils
)
add_subdirectory(libs/open_spiel/open_spiel)

# find mlpack
add_compile_definitions(ARMA_DONT_USE_HDF5)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
find_package(MLPACK REQUIRED)

# add all include directories
include_directories(${CMAKE_SOURCE_DIR} libs/open_spiel ${MLPACK_INCLUDE_DIRS})

# build the executables
add_executable(abstraction src/abstraction.cpp)
target_link_libraries(abstraction ${OPEN_SPIEL_LIBRARIES} ${MLPACK_LIBRARIES})
