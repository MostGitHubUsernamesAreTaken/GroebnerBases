cmake_minimum_required(VERSION 3.11)

# set the project name
project(Groebner VERSION 0.1)

include(FetchContent) # allows cmake to fetch googletest from github
FetchContent_Declare(
  gtest
  GIT_REPOSITORY https://github.com/google/googletest.git
)
FetchContent_MakeAvailable(gtest)

find_package(Threads) # for gtest

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src tst)

# add the executable
add_executable(groebner.app main.cpp)
target_link_libraries(groebner.app PUBLIC src -lginac -lcln)
configure_file(GroebnerConfig.hpp.in GroebnerConfig.hpp)

target_include_directories(groebner.app PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )

# add test executable
add_executable(tester tst/testmain.cpp)
target_link_libraries(tester PUBLIC src gtest ${CMAKE_THREAD_LIBS_INIT} -lginac -lcln)

enable_testing()
include(GoogleTest) # gives access to gtest_discover_tests command
gtest_discover_tests(tester)
