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

TEST(HuntTheWampusTests, GameInterfaceMove){
	MockPlayer mp;
	IGame g(mp);
	
	EXPECT_CALL(mp, move(3))
	.Times(1)
	.WillOnce(Return("13"));
	
	std::string actual = g.move(3);
	
	EXPECT_EQ(actual, "You moved to room 13");
}

TEST(HuntTheWampusTests, GameInterfaceIndication){
	MockPlayer mp;
	IGame g(mp);
	
	EXPECT_CALL(mp, soundsHeard())
	.Times(1)
	.WillOnce(Return("I hear a breeze"));
	
	std::string actual = g.indication();
	
	EXPECT_EQ(actual, "I hear a breeze");
}

TEST(HuntTheWampusTests, GameInterfacePrompt){
	MockPlayer mp;
	IGame g(mp);
	
	g.prompt("Test");
}
