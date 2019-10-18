#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "ILocation.h"
#include "IPlayer.h"

class Player : public IPlayer {
public:
	Player();
	Player(ILocation& l);
	std::string move(int roomChoice) override;
	bool shoot(int roomNo1,int roomNo2, int roomNo3) override;
	std::string soundsHeard(int roomChoice) override;
	void connectedRooms(int& first, int& second, int& third) override;
	bool isAlive() override;
	bool wampusLives() override;
private:
	ILocation* playerLocation;	
};

#endif /*IPLAYER_HPP*/