#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IGame.h"
#include "IPlayer.h"

using ::testing::Return;
using ::testing::Assign;
using ::testing::_;

class MockPlayer : public IPlayer { // refactor this by makeing it its own file
public:
	MOCK_METHOD1(move, std::string(int roomChoice));
	MOCK_METHOD3(shoot, bool(int roomNo1,int roomNo2,int roomNo3));
	MOCK_METHOD0(soundsHeard, std::string());
	MOCK_METHOD0(isAlive, bool());
	MOCK_METHOD0(wampusLives, bool());
	MOCK_METHOD3(connectedRooms, void(int& first, int& second, int& third));
	
};

class MockUserInput : public IUserInput { // refactor this by making it its own file then including it
public:
	MOCK_METHOD0(getInput, std::string());
	MOCK_METHOD0(getInputMove, int());
	MOCK_METHOD3(getInputShoot, void(int& firstRoom, int& secondRoom, int& thirdRoom));
	MOCK_METHOD0(lastInput, std::string());
};

TEST(IGameTests, GameInterfaceMove){
	MockPlayer mp;
	IGame g(mp);
	
	EXPECT_CALL(mp, move(3))
	.Times(1)
	.WillOnce(Return("13"));
	
	std::string actual = g.move(3);
	std::cout << '\n';
	
	EXPECT_EQ(actual, "You moved to room 13");
}

TEST(IGameTests, GameInterfaceShoot){
	MockPlayer mp;
	IGame g(mp);
	
	EXPECT_CALL(mp, shoot(3, 14 ,16))
	.Times(1)
	.WillOnce(Return(false));
	
	std::string actual = g.shoot(3, 14 ,16);
	
	EXPECT_EQ(actual, "You missed the wampus");
}

TEST(IGameTests, GameInterfaceIndication){
	MockPlayer mp;
	IGame g(mp);
	
	EXPECT_CALL(mp, soundsHeard())
	.Times(1)
	.WillOnce(Return("I hear a breeze"));
	
	std::string actual = g.indication();
	std::cout << '\n';
	
	EXPECT_EQ(actual, "I hear a breeze");
}

TEST(IGameTests, GameInterfacePrompt){
	MockPlayer mp;
	IGame g(mp);
	
	g.prompt("This is a test of the prompt() function");
	std::cout << '\n';
}

TEST(IGameTests, GameInterfaceUserInput){
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

TEST(IGameTests, GameInterfaceConnectedRooms){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	
	int actualFirst = 0;
	int actualSecond = 0;
	int actualThird = 0;
	
	EXPECT_CALL(mp, connectedRooms(actualFirst,actualSecond,actualThird))
	.Times(1)
	.WillOnce(DoAll(Assign(&actualFirst, 13),Assign(&actualSecond, 4),Assign(&actualThird, 46)));
	
	std::string actual = g.connectedRooms(actualFirst,actualSecond,actualThird);
	std::string expected = "13 4 46";
	EXPECT_EQ(actualFirst,13);
	EXPECT_EQ(actualSecond,4);
	EXPECT_EQ(actualThird, 46);
	EXPECT_EQ(actual, expected);
}

TEST(IGameTests, GameInterfaceUserInputTypo){
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

TEST(IGameTests, GameInterfaceUserInputShoot){
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

TEST(IGameTests, GameInterfaceUserInputOverloadMove){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	
	EXPECT_CALL(i, getInputMove())
	.Times(1)
	.WillOnce(Return(1));
	int actual;
	
	g.userInput(actual);
	int expected = 1;
	EXPECT_EQ(actual, expected);
}

TEST(IGameTests, GameInterfaceUserInputOverloadShoot){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	int actualFirst = 0;
	int actualSecond = 0;
	int actualThird = 0;
	
	EXPECT_CALL(i, getInputShoot(actualFirst,actualSecond,actualThird))
	.Times(1)
	.WillOnce(DoAll(Assign(&actualFirst, 15),Assign(&actualSecond, 2),Assign(&actualThird, 54)));
	
	int expectedFirst = 15;
	int expectedSecond = 2;
	int expectedThird = 54;
	
	g.userInput(actualFirst,actualSecond,actualThird);
	
	EXPECT_EQ(actualFirst, expectedFirst);
	EXPECT_EQ(actualSecond, expectedSecond);
	EXPECT_EQ(actualThird, expectedThird);
}

TEST(IGameTests, GameInterfaceVerifyTrue){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	//functions return false if lastInput == "quit" then !wampusLives then !isAlive
	//expect calls to those functions only if the previouse one succeeds 
	EXPECT_CALL(i, lastInput())
	.Times(1)
	.WillOnce(Return("move"));
	
	EXPECT_CALL(mp, isAlive())
	.Times(1)
	.WillOnce(Return(true));
	
	EXPECT_CALL(mp, wampusLives())
	.Times(1)
	.WillOnce(Return(true));
	
	bool actual = g.verify();
	
	EXPECT_TRUE(actual);
}

TEST(IGameTests, GameInterfaceVerifyFalseQuit){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	
	EXPECT_CALL(i, lastInput())
	.Times(1)
	.WillOnce(Return("quit"));
	//do not expect the calls of the other function because verify returns
	
	bool actual = g.verify();
	
	EXPECT_FALSE(actual);
}

TEST(IGameTests, GameInterfaceVerifyFalse){
	MockPlayer mp;
	MockUserInput i;
	IGame g(mp,i);
	
	EXPECT_CALL(i, lastInput())
	.Times(1)
	.WillOnce(Return("move"));
	
	EXPECT_CALL(mp, wampusLives())
	.Times(1)
	.WillOnce(Return(true));
	
	EXPECT_CALL(mp, isAlive())
	.Times(1)
	.WillOnce(Return(false));	
	
	bool actual = g.verify();
	
	EXPECT_FALSE(actual);
}



