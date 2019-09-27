#ifndef IGAME_HPP
#define IGAME_HPP
#include <iostream>
#include "IPlayer.h"

class IGame {
	IPlayer* player;
public:
	IGame(IPlayer& p);
	virtual void prompt(std::string s);
	virtual std::string move(int roomChoice);
	virtual std::string indication();
};

#endif /*IGAME_HPP*/