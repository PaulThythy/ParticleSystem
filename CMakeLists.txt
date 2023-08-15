cmake_minimum_required(VERSION 3.7)
project(ParticleSystem)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/cmake-build-debug)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wfatal-errors -Werror -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")


set(SDL2_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2/cmake)

set(SOURCES
        ${CMAKE_SOURCE_DIR}/src/main.cpp
        ${CMAKE_SOURCE_DIR}/src/particle.cpp
        ${CMAKE_SOURCE_DIR}/src/particles.cpp
        ${CMAKE_SOURCE_DIR}/src/application.cpp)
set(HEADERS
        ${CMAKE_SOURCE_DIR}/include/particle.h
        ${CMAKE_SOURCE_DIR}/include/particles.h
        ${CMAKE_SOURCE_DIR}/include/application.h)

# Add the appropriate flags for Windows
if(WIN32)
    # Check if the system is 32-bit or 64-bit
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64)
    else()
        set(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x86)
    endif()

    # Add the SDL2.dll file to the binary directory for Windows
    file(COPY ${SDL2_LIB_DIR}/SDL2.dll DESTINATION ${CMAKE_SOURCE_DIR}/cmake-build-debug)

    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})

    add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64)
    else()
        set(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x86)
    endif()

    set(SDL2_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/libs/SDL2/include)

    include_directories(SDL2_INCLUDE_DIR)
    link_directories(SDL2_LIB_DIR)

    add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
    target_link_libraries(${PROJECT_NAME} SDL2main SDL2)

endif()
