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
	
(UPDATE) I am no longer using cygwin to develope my program. I am using a windows linux subsystem running umbuntu.


general plan

top down design phase one

while(exitcondition)
	Game Indication done
	Game Prompt done 
	Game input done
	Game action(move or shoot) done 
	Game Prompt done 
	exit condition = Game verify done
	
top down design phase two

Game Indication done
	implementation Player -- -- soundsHeard() done
Game Prompt done 
	implementation done 
Game input done
	implementation IUserInput -- -- getInput()
	implementation IUserInput -- -- isValid()
	implementation IUserInput -- -- getInputMove()
	implementation IUserInput -- -- getInputShoot(firstRoom, secondRoom, thirdRoom)
Game action(move or shoot) done 
	implementation Player -- -- move(roomChoice) done 
	implementation Player -- -- shoot(roomNo1,roomNo2,roomNo3) done 
Game Prompt done 
	implementation done
exit condition = Game verify done
	implementation Player -- -- wampusLives() 
	implementation Player -- -- isAlive()
	implementation IUserInput -- -- lastInput()
	
Since I have to implement two classes I have to set up two unit tests.



to do Major refactoring all of the classes labled as interfaces must be made into classes with pure virtual functions and
then real derived classes must be made with their respective implementations

when the time comes to implement the rooms it might be worth while to implement a hash table to access rooms and their information.