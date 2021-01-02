cmake_minimum_required(VERSION 3.10)

# set the project name
project(Groebner VERSION 0.1)
include(gtest.cmake)
find_package(Threads) # gor gtest

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g")

add_subdirectory(src tst)

# add the executable
add_executable(groebner.app main.cpp)
target_link_libraries(groebner.app PUBLIC src -lginac)
configure_file(GroebnerConfig.hpp.in GroebnerConfig.hpp)

target_include_directories(groebner.app PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )


# add test executable
add_executable(tester tst/testmain.cpp)
target_link_libraries(tester PUBLIC src gtest ${CMAKE_THREAD_LIBS_INIT} -lginac)

enable_testing()
include(GoogleTest)
gtest_discover_tests(tester)
