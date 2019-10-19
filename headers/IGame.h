#ifndef IGAME_HPP
#define IGAME_HPP

class IGame {
public:
	virtual void prompt(std::string s) = 0;
	virtual std::string connectedRooms(int& first, int& second, int& third) = 0;
	virtual std::string move(int roomChoice) = 0;
	virtual std::string shoot(int roomNo1, int roomNo2, int roomNo3) = 0;
	virtual std::string indication() = 0;
	virtual char userInput() = 0;
	virtual void userInput(int& roomNumber) = 0;
	virtual void userInput(int& firstRoom, int& secondRoom, int& thirdRoom) = 0;
	virtual bool verify() = 0;
};

#endif /*IGAME_HPP*/