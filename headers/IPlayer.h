#ifndef IPLAYER_HPP
#define IPLAYER_HPP
#include <iostream>

class IPlayer {
	public:
	virtual std::string move(int roomChoice);
	virtual bool shoot(int roomNo1,int roomNo2, int roomNo3);
	virtual std::string soundsHeard();
	virtual bool isAlive();
	virtual bool wampusLives();
};

#endif /*IPLAYER_HPP*/