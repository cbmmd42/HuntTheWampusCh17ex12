#ifndef IUSERINPUT_HPP
#define IUSERINPUT_HPP
#include <iostream>

class IUserInput {
    public:
    virtual std::string getInput() = 0;
	virtual std::string lastInput() = 0;
	virtual int getInputMove() = 0;
	virtual void getInputShoot(int& firstRoom, int& secondRoom, int& thirdRoom) = 0;
	virtual bool isValid(std::string s) = 0;
};

#endif /*IUSERINPUT_HPP*/