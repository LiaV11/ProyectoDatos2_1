cmake_minimum_required(VERSION 3.10)
project(ProyectoDatos2_1)

set(CMAKE_CXX_STANDARD 20)

# Añade Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Añade los archivos fuente
add_executable(ProyectoDatos2_1 main.cpp MPointerGC.cpp DoublyLinkedList.cpp
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        main.cpp
        main.cpp)

# Vincula Google Test
target_link_libraries(ProyectoDatos2_1 ${GTEST_LIBRARIES} pthread)
