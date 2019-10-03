cmake_minimum_required(VERSION 3.1)

set(This IGame)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

include_directories(./headers/)

set(Headers 
	headers/IGame.h
	headers/IPlayer.h
	headers/IUserInput.h
)

set(Sources
	sources/IGame.cpp
	sources/IPlayer.cpp
	sources/IUserInput.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})

add_subdirectory(test)

