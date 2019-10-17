#include "IPlayer.h"

IPlayer::IPlayer(){
	playerLocation = nullptr;
}

IPlayer::IPlayer(ILocation& l){
	playerLocation = &l;
}

std::string IPlayer::move(int roomChoice){
	playerLocation = playerLocation->goThroughTunnel(roomChoice);
	if(playerLocation == nullptr) return "Invalid state";
	int roomNumberInt = playerLocation->roomNumber();
	std::string roomNumber = std::to_string(roomNumberInt);
	return roomNumber;
}

bool IPlayer::shoot(int roomNo1, int roomNo2, int roomNo3){
	//if(!playerLocation->isConnected(roomNo1)){ return false; }
	int tunnelNo = playerLocation->findTunnelNoFromRoomNo(roomNo1);
	ILocation* firstLocation = playerLocation->goThroughTunnel(tunnelNo);
	if(firstLocation->thingStr() == "wampus") return true;
	
	tunnelNo = firstLocation->findTunnelNoFromRoomNo(roomNo2);
	ILocation* secondLocation = firstLocation->goThroughTunnel(tunnelNo);
	if(secondLocation->thingStr() == "wampus") return true;
	
	tunnelNo = secondLocation->findTunnelNoFromRoomNo(roomNo3);
	ILocation* thirdLocation = secondLocation->goThroughTunnel(tunnelNo);
	if(thirdLocation->thingStr() == "wampus") return true;
	
	return false;
}

bool IPlayer::isAlive() {
	return true;
}

bool IPlayer::wampusLives(){
	return true;
}

std::string thingStringToOutput(std::string thingString){
	if(thingString == "pit"){
		return "I hear a breeze";
	} else if(thingString == "wampus") {
		return "I smell the wampus";
	}	else {
		return "I hear a " + thingString;
	}
}

std::string IPlayer::soundsHeard(int roomChoice) {
	std::string thingFirstTunnel = playerLocation->goThroughTunnel(roomChoice)->thingStr();	
	return thingStringToOutput(thingFirstTunnel);
}

void IPlayer::connectedRooms(int& first, int& second, int& third){
	
}