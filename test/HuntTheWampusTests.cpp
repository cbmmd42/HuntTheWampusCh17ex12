#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../IGame.h"
#include "../IPlayer.h"

using ::testing::Return;

class MockPlayer : public IPlayer {
public:
	MOCK_METHOD1(move, std::string(int roomChoice));
	MOCK_METHOD0(soundsHeard, std::string());
};

class MockUserInput : public IUserInput {
public:
	MOCK_METHOD0(getInput, std::string());
};

TEST(HuntTheWampusTests, GameInterfaceMove){
	MockPlayer mp;
	IGame g(mp);
	
	EXPECT_CALL(mp, move(3))
	.Times(1)
	.WillOnce(Return("13"));
	
	std::string actual = g.move(3);
	std::cout << '\n';
	
	EXPECT_EQ(actual, "You moved to room 13");
}

TEST(HuntTheWampusTests, GameInterfaceIndication){
	MockPlayer mp;
	IGame g(mp);
	
	EXPECT_CALL(mp, soundsHeard())
	.Times(1)
	.WillOnce(Return("I hear a breeze"));
	
	std::string actual = g.indication();
	std::cout << '\n';
	
	EXPECT_EQ(actual, "I hear a breeze");
}

TEST(HuntTheWampusTests, GameInterfacePrompt){
	MockPlayer mp;
	IGame g(mp);
	
	g.prompt("This is a test of the prompt() function");
	std::cout << '\n';
}

TEST(HuntTheWampusTests, GameInterfaceUserInput){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	
	EXPECT_CALL(i, getInput())
	.Times(1)
	.WillOnce(Return("move"));
	
	char actual = g.userInput();
	char expected = 'm';
	EXPECT_EQ(actual, expected);
}

TEST(HuntTheWampusTests, GameInterfaceUserInputTypo){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	
	EXPECT_CALL(i, getInput())
	.Times(2)
	.WillOnce(Return("mve"))
	.WillOnce(Return("move"));
	
	char actual = g.userInput();
	char expected = 'm';
	EXPECT_EQ(actual, expected);
}

TEST(HuntTheWampusTests, GameInterfaceUserInputShoot){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	
	EXPECT_CALL(i, getInput())
	.Times(1)
	.WillOnce(Return("shoot"));
	
	char actual = g.userInput();
	char expected = 's';
	EXPECT_EQ(actual, expected);
}

