#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../IGame.h"
#include "../IPlayer.h"

using ::testing::Return;

class MockPlayer : public IPlayer {
public:
	MOCK_METHOD0(move, std::string());
};

TEST(HuntTheWampusTests, GameInterface){
	MockPlayer mp;
	IGame g(mp);
	
	EXPECT_CALL(mp, move())
	.Times(1)
	.WillOnce(Return(""));
	
	std::string actual = g.move();
	
	EXPECT_EQ(actual, "");
}

