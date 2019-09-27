#include "IGame.h"

IGame::IGame(IPlayer& p)
{
	player = &p;
}

void IGame::prompt(std::string s){
	std::cout << s;
}

std::string IGame::move(int roomChoice){
		std::string roomNumber = player->move(roomChoice);
		//prompt("You moved to room " + roomNumber);
		return "You moved to room " + roomNumber;
}

std::string IGame::indication(){
		return player->soundsHeard();
}