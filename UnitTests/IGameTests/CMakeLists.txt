cmake_minimum_required(VERSION 3.1)

set(This IGameTests)

set(Sources
	IGameTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
	gtest_main
	gmock_main
	IGame
)

add_test(
	NAME ${This}
	COMMAND ${This}
)