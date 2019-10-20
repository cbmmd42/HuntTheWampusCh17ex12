#include "UserInput.h"

std::string UserInput::getInput(){
	return "";
}

std::string UserInput::lastInput(){
	return "";
}

int UserInput::getInputMove(){
	return 0;
}

void UserInput::getInputShoot(int& firstRoom, int& secondRoom, int& thirdRoom){
	
}

bool UserInput::isValid(std::string s) {
	if(s == "move" || s == "shoot"){
		return true;
	}
	return false;
}