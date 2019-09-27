cmake_minimum_required(VERSION 3.15.3)

set(This HuntTheWampus)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers 
	IGame.h
	IPlayer.h
)

set(Sources
	IGame.cpp
	IPlayer.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(test)

