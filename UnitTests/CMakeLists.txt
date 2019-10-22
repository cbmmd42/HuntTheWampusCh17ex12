cmake_minimum_required(VERSION 3.1)

set(This UnitTests)

project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

include_directories(../headers/)

set(GameHeaders 
	../headers/Game.h
	../headers/IPlayer.h
	../headers/IUserInput.h
)

set(PlayerHeaders 
	../headers/IPlayer.h
)

set(UserInputHeaders 
	../headers/UserInput.h
)

set(GameSources
	../sources/Game.cpp
	../sources/Player.cpp
)

set(PlayerSources
	../sources/Player.cpp
)

set(UserInputSources
	../sources/UserInput.cpp
)

add_library(Game STATIC ${GameHeaders} ${GameSources})

add_library(Player STATIC ${PlayerHeaders} ${PlayerSources})

add_library(UserInput STATIC ${UserInputHeaders} ${UserInputSources})

add_subdirectory(GameTests)

add_subdirectory(PlayerTests)

add_subdirectory(UserInputTests)

