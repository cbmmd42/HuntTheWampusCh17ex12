#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include "IPlayer.h"
#include "IUserInput.h"
#include "IGame.h"

class Game : public IGame {
	IPlayer* player;
	IUserInput* gameInput;
public:
	Game(IPlayer& p, IUserInput& i);
	virtual void prompt(std::string s) override;
	virtual std::string connectedRooms(int& first, int& second, int& third) override;
	virtual std::string move(int roomChoice);
	virtual std::string shoot(int roomNo1, int roomNo2, int roomNo3) override;
	virtual std::string indication() override;
	virtual char userInput() override;
	virtual void userInput(int& roomNumber) override;
	virtual void userInput(int& firstRoom, int& secondRoom, int& thirdRoom) override;
	virtual bool verify() override;
};

#endif /*IGAME_HPP*/