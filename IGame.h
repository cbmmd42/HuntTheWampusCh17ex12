#ifndef IGAME_HPP
#define IGAME_HPP
#include <iostream>
#include "IPlayer.h"

class IGame {
	IPlayer* player;
public:
	IGame(IPlayer& p);
	std::string move();
};

#endif /*IGAME_HPP*/