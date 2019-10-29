cmake_minimum_required(VERSION 3.1)

set(This UserInputTests)

set(Sources
	UserInputTests.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
	gtest_main
	gmock_main
	UserInput
)

add_test(
	NAME ${This}
	COMMAND ${This}
)