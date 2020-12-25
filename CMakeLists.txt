cmake_minimum_required(VERSION 3.10)

# set the project name
project(Groebner VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src tst)

# add the executable
add_executable(groebner.app main.cpp)
target_link_libraries(groebner.app PUBLIC src -lginac)
configure_file(GroebnerConfig.h.in GroebnerConfig.h)

target_include_directories(groebner.app PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )

# add test executable
add_executable(tester tst/multinomial_test.cpp)
target_link_libraries(tester PUBLIC src -lgtest -lginac)

enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)
gtest_discover_tests(tester)
