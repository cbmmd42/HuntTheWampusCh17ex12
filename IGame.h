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
	virtual std::string indication();
	virtual char userInput();
};

#endif /*IGAME_HPP*/