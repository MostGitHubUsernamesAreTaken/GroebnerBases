cmake_minimum_required(VERSION 3.10)

# set the project name
project(Groebner VERSION 0.1)

add_subdirectory(src)

# add the executable
add_executable(groebner.app main.cpp)

target_link_libraries(groebner.app PUBLIC src -lginac)

configure_file(GroebnerConfig.h.in GroebnerConfig.h)

target_include_directories(groebner.app PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}"
                           )
