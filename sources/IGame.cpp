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
		prompt("You moved to room " + roomNumber); //refactor separate input and output from actual game logic
		return "You moved to room " + roomNumber;
}

std::string IGame::shoot(int roomNo1, int roomNo2, int roomNo3){
	return (player->shoot(roomNo1,roomNo2,roomNo3)) ? "You hit the wampus" : "You missed the wampus";
}

std::string addSound(std::string s,bool& moreThanOneSound){
	if(s == "") return "";
	
	if(!moreThanOneSound){
		moreThanOneSound = true;
		return s;
	} else {
		return " and " + s;
	}
	
}

std::string IGame::indication(){
	std::string sound = "";	
	const int numberOfConnectedRooms = 3;
	bool moreThanOneSound = false;
	
	for(int currentRoom = 1; currentRoom <= numberOfConnectedRooms; ++currentRoom){
			sound += addSound(player->soundsHeard(currentRoom),moreThanOneSound);
	}
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
	while(!isValid(input)){ // refactor to put isValid in UserInput
		input = gameInput->getInput();
	}		
	return input[0];
}

void IGame::userInput(int& roomNumber) {
	roomNumber = gameInput->getInputMove();
}

void IGame::userInput(int& firstRoom, int& secondRoom, int& thirdRoom){
	gameInput->getInputShoot(firstRoom, secondRoom, thirdRoom);
}

bool IGame::verify(){
	bool keepPlaying = true;
	if(gameInput->lastInput() == "quit") return false;
	if(!player->wampusLives()) return false;
	if(!player->isAlive()) return false;	
	return keepPlaying;
}

std::string IGame::connectedRooms(int& first, int& second, int& third){
	player->connectedRooms(first,second,third);
	return std::to_string(first) + " " + std::to_string(second) + " " + std::to_string(third);
}