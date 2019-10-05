# HuntTheWampusCh18ex12
Exercise 12 of chapter 18 in Programming principles and practice using c++

I'm kind of new to CMake but I set up the files so that you could run unit tests and add tests without violating the open 
closed principle for the most part.

Set up the tests and run the code, first you must clone google 
test into the directory HuntTheWampusCh18ex12/UnitTests
then run cmake. Use the generated makefiles to finish the build. 
The executable to run your tests will show up in the /<InterfaceName>Tests directory.
I am using the gcc g++ compiler, cygwin bash shell and cmake configured 
to run on my command line.

To run my tests to get started on Test Driven Development I run these commands.
	1st change to my UnitTests directory
	2nd enter 'cmake -G "Unix Makefiles" . ' period included
	3rd run this command 'make'
	4th change directory to the interface I am testing 'cd IGameTests'
	5th run 'IGameTests.exe'
	6th make changes to IGameTests.cpp and save
	7th run make again from the current directory


general plan

top down design phase one

while(exitcondition)
	IGame Indication done
	IGame Prompt done 
	IGame input done
	IGame action(move or shoot) done 
	IGame Prompt done 
	exit condition = IGame verify done
	
top down design phase two

IGame Indication done
	implementation IPlayer -- -- soundsHeard()
IGame Prompt done 
	implementation done 
IGame input done
	implementation IUserInput -- -- getInput()
	implementation IUserInput -- -- isValid()
	implementation IUserInput -- -- getInputMove()
	implementation IUserInput -- -- getInputShoot(firstRoom, secondRoom, thirdRoom)
IGame action(move or shoot) done 
	implementation IPlayer -- -- move(roomChoice)
	implementation IPlayer -- -- shoot(roomNo1,roomNo2,roomNo3)
IGame Prompt done 
	implementation done
exit condition = IGame verify done
	implementation IPlayer -- -- wampusLives()
	implementation IPlayer -- -- isAlive()
	implementation IUserInput -- -- lastInput()
	
Since I have to implement two classes I have to set up two unit tests.



to do Major refactoring all of the classes labled as interfaces must be made into classes with pure virtual functions and
then real derived classes must be made with their respective implementations