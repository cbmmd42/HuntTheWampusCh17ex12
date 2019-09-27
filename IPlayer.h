#ifndef IPLAYER_HPP
#define IPLAYER_HPP
#include <iostream>

class IPlayer {
	public:
	virtual std::string move(int roomChoice);
	virtual std::string soundsHeard();
};

#endif /*IPLAYER_HPP*/