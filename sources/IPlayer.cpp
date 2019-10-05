#include "IPlayer.h"

IPlayer::IPlayer(){
	playerLocation = nullptr;
}

IPlayer::IPlayer(ILocation& l){
	playerLocation = &l;
}

std::string IPlayer::move(int roomChoice){
	playerLocation = playerLocation->goThroughTunnel(roomChoice);
	int roomNumberInt = playerLocation->roomNumber();
	std::string roomNumber = std::to_string(roomNumberInt);
	return roomNumber;
}

bool IPlayer::shoot(int roomNo1, int roomNo2, int roomNo3){
	return false;
}

bool IPlayer::isAlive() {
	return true;
}

bool IPlayer::wampusLives(){
	return true;
}

std::string IPlayer::soundsHeard() {
	//std::string roomNumber = "13";
	return "I hear a breeze";
}