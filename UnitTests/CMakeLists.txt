cmake_minimum_required(VERSION 3.1)

set(This IGame)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

include_directories(../headers/)

set(IGameHeaders 
	../headers/IGame.h
	../headers/IPlayer.h
	../headers/IUserInput.h
)

set(IPlayerHeaders 
	../headers/IPlayer.h
)

set(IGameSources
	../sources/IGame.cpp
	../sources/Player.cpp
	../sources/IUserInput.cpp
)

set(IPlayerSources
	../sources/Player.cpp
)

add_library(IGame STATIC ${IGameHeaders} ${IGameSources})

add_library(IPlayer STATIC ${IPlayerHeaders} ${IPlayerSources})

add_subdirectory(IGameTests)

add_subdirectory(IPlayerTests)

