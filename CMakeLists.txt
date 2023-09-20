cmake_minimum_required(VERSION 3.23)
project(Graph_algorithm_Native_and_Ram)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sample_one sample_one.cpp Graph.h DSU.h Graph.cpp DSU.cpp)
add_executable(Sample_two sample_two.cpp Graph.h DSU.h Graph.cpp DSU.cpp)
add_executable(test_3.1 test_3.1.cpp Graph.h DSU.h Graph.cpp DSU.cpp)
add_executable(test_3.2 test_3.2.cpp Graph.h DSU.h Graph.cpp DSU.cpp)
add_executable(test_3.3 test_3.3.cpp Graph.h DSU.h Graph.cpp DSU.cpp)
add_executable(test_3.4 test_3.4.cpp Graph.h DSU.h Graph.cpp DSU.cpp)