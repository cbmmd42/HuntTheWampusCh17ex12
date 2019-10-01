#ifndef IPLAYER_HPP
#define IPLAYER_HPP
#include <iostream>

class IPlayer {
	public:
	virtual std::string move(int roomChoice);
	virtual bool shoot(int roomNo1,int roomNo2, int roomNo3) = 0;
	virtual std::string soundsHeard();
};

#endif /*IPLAYER_HPP*/