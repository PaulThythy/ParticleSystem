cmake_minimum_required(VERSION 3.22)
project(ParticleSystem)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/cmake-build-debug)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})

execute_process(COMMAND ${CMAKE_COMMAND} -E chdir ${CMAKE_BINARY_DIR})

set(SDL2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2-2.26.2/include)
set(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2-2.26.2/lib/x86)

set(SOURCES
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/particle.cpp
        ${CMAKE_SOURCE_DIR}/src/particles.cpp)
set(HEADERS
        ${CMAKE_SOURCE_DIR}/include/particle.h
        ${CMAKE_SOURCE_DIR}/include/particles.h
        ${CMAKE_SOURCE_DIR}/include/constants.h)

include_directories(SDL2_INCLUDE_DIR)
link_directories(SDL2_LIB_DIR)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)
