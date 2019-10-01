#ifndef IGAME_HPP
#define IGAME_HPP
#include <iostream>
#include "IPlayer.h"
#include "IUserInput.h"

class IGame {
	IPlayer* player;
	IUserInput* gameInput;
public:
	IGame(IPlayer& p);
	IGame(IPlayer& p, IUserInput& i);
	virtual void prompt(std::string s);
	virtual std::string move(int roomChoice);
	virtual std::string shoot(int roomNo1, int roomNo2, int roomNo3);
	virtual std::string indication();
	virtual char userInput();
	virtual void userInput(int& roomNumber);
	virtual void userInput(int& firstRoom, int& secondRoom, int& thirdRoom);
};

#endif /*IGAME_HPP*/