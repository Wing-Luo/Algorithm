cmake_minimum_required(VERSION 3.6)
project(AlgorithmCompetition)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



add_subdirectory("2017 star of baidu")
add_subdirectory("hdoj")
add_subdirectory("PAT (Advanced Level)")
add_subdirectory("poj")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")