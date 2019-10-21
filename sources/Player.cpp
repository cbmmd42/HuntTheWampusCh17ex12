#include "Player.h"


Player::Player(ILocation& l){
	playerLocation = &l;
	wampusIsAlive = true;
}

std::string Player::move(int roomChoice){
	playerLocation = playerLocation->goThroughTunnel(roomChoice);
	if(playerLocation == nullptr) return "Invalid state";
	int roomNumberInt = playerLocation->roomNumber();
	std::string roomNumber = std::to_string(roomNumberInt);
	return roomNumber;
}



bool Player::shoot(int roomNo1, int roomNo2, int roomNo3){

	int tunnelNo = playerLocation->findTunnelNoFromRoomNo(roomNo1);
	ILocation* firstLocation = playerLocation->goThroughTunnel(tunnelNo);
	if(firstLocation->thingStr() == "wampus") {
		wampusIsAlive = false;
		return true; // refactor
	}
	
	tunnelNo = firstLocation->findTunnelNoFromRoomNo(roomNo2);
	ILocation* secondLocation = firstLocation->goThroughTunnel(tunnelNo);
	if(secondLocation->thingStr() == "wampus") {
		wampusIsAlive = false;
		return true;
	}
	
	tunnelNo = secondLocation->findTunnelNoFromRoomNo(roomNo3);
	ILocation* thirdLocation = secondLocation->goThroughTunnel(tunnelNo);
	if(thirdLocation->thingStr() == "wampus") {
		wampusIsAlive = false;
		return true;
	}
	
	return false;
}

bool Player::isAlive() {
	std::string thing = playerLocation->thingStr();
	if(thing == "wampus"|| thing == "pit") return false;
	return true;
}

bool Player::wampusLives(){	
	return wampusIsAlive;
}

std::string thingStringToOutput(std::string thingString){
	if(thingString == "pit"){
		return "I hear a breeze";
	} else if(thingString == "wampus") {
		return "I smell the wampus";
	} else if(thingString == "") {
		return "";
	} else {
		return "I hear a " + thingString;
	}
}

std::string Player::soundsHeard(int roomChoice) {
	std::string thingFirstTunnel = playerLocation->goThroughTunnel(roomChoice)->thingStr();	
	return thingStringToOutput(thingFirstTunnel);
}

void Player::connectedRooms(int& first, int& second, int& third){
	
}