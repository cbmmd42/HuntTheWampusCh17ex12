#ifndef IPLAYER_HPP
#define IPLAYER_HPP
#include <iostream>
#include "ILocation.h"

class IPlayer {
public:
	IPlayer();
	IPlayer(ILocation& l);
	virtual std::string move(int roomChoice);
	virtual bool shoot(int roomNo1,int roomNo2, int roomNo3);
	virtual std::string soundsHeard();
	virtual bool isAlive();
	virtual bool wampusLives();
private:
	ILocation* playerLocation;	
};

#endif /*IPLAYER_HPP*/