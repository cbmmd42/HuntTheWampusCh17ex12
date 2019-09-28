#include "IGame.h"

IGame::IGame(IPlayer& p)
{
	player = &p;
	gameInput = new IUserInput();
}

IGame::IGame(IPlayer& p, IUserInput& i)
{
	player = &p;
	gameInput = &i;
}

void IGame::prompt(std::string s){
	std::cout << s;
}

std::string IGame::move(int roomChoice){
		std::string roomNumber = player->move(roomChoice);
		prompt("You moved to room " + roomNumber);
		return "You moved to room " + roomNumber;
}

std::string IGame::indication(){
		std::string sound = player->soundsHeard();
		prompt(sound);
		return sound;
}

bool isValid(std::string s) {
	if(s == "move" || s == "shoot"){
		return true;
	}
	return false;
}

char IGame::userInput() {
	std::string input = gameInput->getInput();
	while(!isValid(input)){
		input = gameInput->getInput();
	}		
	return input[0];
}