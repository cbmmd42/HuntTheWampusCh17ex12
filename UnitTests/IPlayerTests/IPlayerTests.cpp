#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "IPlayer.h"
#include "ILocation.h"

using ::testing::Return;
using ::testing::Assign;


class MockLocation : public ILocation { // refactor this by making it its own file then include it
	public:
	MOCK_METHOD0(roomNumber, int());
	MOCK_METHOD1(isConnected, bool(int roomNumber));
	MOCK_METHOD1(findTunnelNoFromRoomNo, int(int roomNo));
	MOCK_METHOD0(thingStr, std::string());
	MOCK_METHOD1(goThroughTunnel, ILocation*(int roomNumber));
	
};


TEST(IPlayerTests, PlayerMoveOneCall){
	MockLocation pLocation23ConToRm54;
	MockLocation* pLocation54ConToRm23 = new MockLocation();
	IPlayer player(pLocation23ConToRm54); 
	
	EXPECT_CALL(pLocation23ConToRm54, goThroughTunnel(1))
		.Times(1)
		.WillOnce(Return(pLocation54ConToRm23));
	EXPECT_CALL(*pLocation54ConToRm23, roomNumber())
		.Times(1)
		.WillOnce(Return(54));
		
	std::string expected = "54";
	std::string actual = player.move(1);
	
	EXPECT_EQ(actual,expected);	
	delete pLocation54ConToRm23;
}

TEST(IPlayerTests, PlayerMoveTwoCalls){
	MockLocation pLocation23ConToRm54;
	MockLocation* pLocation54ConToRm23 = new MockLocation();
	MockLocation* pLocation33ConToRm54 = new MockLocation();
	IPlayer player(pLocation23ConToRm54); 
	
	EXPECT_CALL(pLocation23ConToRm54, goThroughTunnel(1))
		.Times(1)
		.WillOnce(Return(pLocation54ConToRm23));
	EXPECT_CALL(*pLocation54ConToRm23, roomNumber())
		.Times(1)
		.WillOnce(Return(54));
	EXPECT_CALL(*pLocation54ConToRm23, goThroughTunnel(2))
		.Times(1)
		.WillOnce(Return(pLocation33ConToRm54));
	EXPECT_CALL(*pLocation33ConToRm54, roomNumber())
		.Times(1)
		.WillOnce(Return(33));
		
	std::string expected = "33";
	player.move(1);
	std::string actual = player.move(2);
	
	EXPECT_EQ(actual,expected);	
	delete pLocation54ConToRm23;
	delete pLocation33ConToRm54;
}

TEST(IPlayerTests, PlayerMoveNullptr){
	MockLocation pLocation23ConToRm54;;
	IPlayer player(pLocation23ConToRm54); 
	
	EXPECT_CALL(pLocation23ConToRm54, goThroughTunnel(1))
		.Times(1)
		.WillOnce(Return(nullptr));
		
	std::string expected = "Invalid state";
	std::string actual = player.move(1);
	
	EXPECT_EQ(actual,expected);	
}

TEST(IPlayerTests, PlayerShootWampusInFirst){
	MockLocation* pLocation15ConToRm1 = new MockLocation();
	MockLocation* pLocation1ConToRm5 = new MockLocation();
	IPlayer player(*pLocation15ConToRm1); 	
	
	EXPECT_CALL(*pLocation15ConToRm1, findTunnelNoFromRoomNo(5))
		.Times(1)
		.WillOnce(Return(1));
	EXPECT_CALL(*pLocation15ConToRm1, goThroughTunnel(1))
		.Times(1)
		.WillOnce(Return(pLocation1ConToRm5));
	EXPECT_CALL(*pLocation1ConToRm5, thingStr())
		.Times(1)
		.WillOnce(Return("Wampus"));	
	bool actual = player.shoot(5,7,54);
	
	EXPECT_TRUE(actual);
	delete pLocation15ConToRm1;
	delete pLocation1ConToRm5; 
}

TEST(IPlayerTests, PlayerShootWampusInSecond){
	MockLocation* pLocation15ConToRm1 = new MockLocation();
	MockLocation* pLocation1ConToRm5 = new MockLocation();
	MockLocation* pLocation5ConToRm7 = new MockLocation();
	IPlayer player(*pLocation15ConToRm1); 
		
	EXPECT_CALL(*pLocation15ConToRm1, findTunnelNoFromRoomNo(5))
		.Times(1)
		.WillOnce(Return(1));
	EXPECT_CALL(*pLocation15ConToRm1, goThroughTunnel(1))
		.Times(1)
		.WillOnce(Return(pLocation1ConToRm5));
	EXPECT_CALL(*pLocation1ConToRm5, thingStr())
		.Times(1)
		.WillOnce(Return("Bat"));
	EXPECT_CALL(*pLocation1ConToRm5, findTunnelNoFromRoomNo(7))
		.Times(1)
		.WillOnce(Return(2));
	EXPECT_CALL(*pLocation1ConToRm5, goThroughTunnel(2))
		.Times(1)
		.WillOnce(Return(pLocation5ConToRm7));
	EXPECT_CALL(*pLocation5ConToRm7, thingStr())
		.Times(1)
		.WillOnce(Return("Wampus"));
	
	bool actual = player.shoot(5,7,54);
	
	EXPECT_TRUE(actual);
	delete pLocation15ConToRm1;
	delete pLocation1ConToRm5; 
	delete pLocation5ConToRm7;
}

TEST(IPlayerTests, PlayerShootWampusInThird){
	MockLocation* pLocation15ConToRm1 = new MockLocation();
	MockLocation* pLocation1ConToRm5 = new MockLocation();
	MockLocation* pLocation5ConToRm7 = new MockLocation();
	MockLocation* pLocation7ConToRm54 = new MockLocation();
	IPlayer player(*pLocation15ConToRm1); 
	
	
	
	EXPECT_CALL(*pLocation15ConToRm1, findTunnelNoFromRoomNo(5))
		.Times(1)
		.WillOnce(Return(1));
	EXPECT_CALL(*pLocation15ConToRm1, goThroughTunnel(1))
		.Times(1)
		.WillOnce(Return(pLocation1ConToRm5));
	EXPECT_CALL(*pLocation1ConToRm5, thingStr())
		.Times(1)
		.WillOnce(Return("Bat"));
	EXPECT_CALL(*pLocation1ConToRm5, findTunnelNoFromRoomNo(7))
		.Times(1)
		.WillOnce(Return(2));
	EXPECT_CALL(*pLocation1ConToRm5, goThroughTunnel(2))
		.Times(1)
		.WillOnce(Return(pLocation5ConToRm7));
	EXPECT_CALL(*pLocation5ConToRm7, thingStr())
		.Times(1)
		.WillOnce(Return("Pit"));
	EXPECT_CALL(*pLocation5ConToRm7, findTunnelNoFromRoomNo(54))
		.Times(1)
		.WillOnce(Return(3));
	EXPECT_CALL(*pLocation5ConToRm7, goThroughTunnel(3))
		.Times(1)
		.WillOnce(Return(pLocation7ConToRm54));
	EXPECT_CALL(*pLocation7ConToRm54, thingStr())
		.Times(1)
		.WillOnce(Return("Wampus"));
	
	
	bool actual = player.shoot(5,7,54);
	
	EXPECT_TRUE(actual);
	delete pLocation15ConToRm1;
	delete pLocation1ConToRm5; 
	delete pLocation5ConToRm7;
	delete pLocation7ConToRm54;	
}

/*test for corruption*/


