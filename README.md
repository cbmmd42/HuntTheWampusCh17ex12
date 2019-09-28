# HuntTheWampusCh18ex12
Exercise 12 of chapter 18 in Programming principles and practice using c++

To run this, clone google test into the directory HuntTheWampusCh18ex12 then run cmake. 
Use the generated makefiles to finish the build. The executable to run your tests will show up in the /test directory.
I am using the gcc g++ compiler, cygwin bash shell and cmake configured to run on my command line.

To run my tests to get started on Test Driven Development I run these four commands.
	1st 'cmake -G "Unix Makefiles" . '
	2nd 'make'
	3rd 'cd test'
	4th 'HuntTheWampusTests.exe'
to recompile use the make command.

general plan

while(exitcondition)
	IGame Indication
	IGame Prompt
	IGame input
	IGame action(move or shoot)
	IGame Prompt
	exit condition = IGame verify
	
