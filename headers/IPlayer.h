#ifndef IPLAYER_HPP
#define IPLAYER_HPP
#include <iostream>
#include "ILocation.h"

class IPlayer {
public:
	virtual std::string move(int roomChoice) = 0;
	virtual bool shoot(int roomNo1,int roomNo2, int roomNo3) = 0;
	virtual std::string soundsHeard(int roomChoice) = 0;
	virtual void connectedRooms(int& first, int& second, int& third) = 0;
	virtual bool isAlive() = 0;
	virtual bool wampusLives() = 0;
};

#endif /*IPLAYER_HPP*/