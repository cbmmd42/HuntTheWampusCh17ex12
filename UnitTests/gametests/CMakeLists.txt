cmake_minimum_required(VERSION 3.1)

set(This GameTests)

set(Sources
	GameTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
	gtest_main
	gmock_main
	Game
)

add_test(
	NAME ${This}
	COMMAND ${This}
)