#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IPlayer.h"
#include "ILocation.h"

using ::testing::Return;
using ::testing::Assign;


class MockLocation : public ILocation { // refactor this by making it its own file then include it
	public:
	MOCK_METHOD0(roomNumber, int());
	MOCK_METHOD1(goThroughTunnel, ILocation*(int roomNumber));
};

TEST(IPlayerTests, PlayerMoveReturnVal){
	MockLocation pLocation;
	IPlayer player(pLocation); 
	
	EXPECT_CALL(pLocation, roomNumber())
		.Times(1)
		.WillOnce(Return(54));
	EXPECT_CALL(pLocation, goThroughTunnel(2))
		.Times(1);
	
	std::string actual = player.move(2);
	std::string expected = "54";
	EXPECT_EQ(actual,expected);	
}

TEST(IPlayerTests, PlayerMoveLocationChange){
	MockLocation pLocation;
	IPlayer player(pLocation); 
	
	EXPECT_CALL(pLocation, roomNumber())
		.Times(2)
		.WillOnce(Return(54))
		.WillOnce(Return(23));
	EXPECT_CALL(pLocation, goThroughTunnel(1))
		.Times(1);
	EXPECT_CALL(pLocation, goThroughTunnel(1))
		.Times(1);
		
	
	std::string first = player.move(1);
	std::string second = player.move(1);
	EXPECT_NE(first,second);	
}



