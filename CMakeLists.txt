cmake_minimum_required(VERSION 3.22.1)
project(game)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sources CONFIGURE_DEPENDS src/*.cpp)
# file(GLOB tests CONFIGURE_DEPENDS tests/*.cpp)

link_libraries(sfml-graphics sfml-window sfml-audio sfml-network sfml-system)

add_executable(run ${sources} main.cpp)
add_executable(test ${sources} tests.cpp)
