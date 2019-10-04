#ifndef IUSERINPUT_HPP
#define IUSERINPUT_HPP
#include <iostream>

class IUserInput {
    public:
    virtual std::string getInput();
	virtual std::string lastInput();
	virtual int getInputMove();
	virtual void getInputShoot(int& firstRoom, int& secondRoom, int& thirdRoom);
};

#endif /*IUSERINPUT_HPP*/