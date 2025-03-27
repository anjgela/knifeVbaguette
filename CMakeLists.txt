cmake_minimum_required(VERSION 3.26)
project(labpro)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(SFML/include)

set(SOURCE_FILES Graph.h
        MapSearch.h
        Graph.cpp
        MapSearch.cpp
        findpath.cpp
        stlastar.h
        fsa.h
        Character.h
        Character.cpp
        Knife.cpp
        Knife.h
        Baguette.cpp
        Baguette.h
        Node.cpp
        Node.h
        Node.h
        Node.cpp
        Menu.cpp
        Menu.h
        Match.cpp
        Match.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(core sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

add_executable(
        labpro main.cpp)
target_link_libraries(labpro core)