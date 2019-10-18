#ifndef USERINPUT_HPP
#define USERINPUT_HPP
#include "IUserInput.h"
#include <iostream>

class UserInput : public IUserInput {
    public:
    virtual std::string getInput() override;
	virtual std::string lastInput() override;
	virtual int getInputMove() override;
	virtual void getInputShoot(int& firstRoom, int& secondRoom, int& thirdRoom) override;
};

#endif /*USERINPUT_HPP*/