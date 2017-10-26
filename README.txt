To run:
make
check.o was left outside of the object list as make clean would remove it
and I did not have access to check.c to recompile it.

File List:
-.spellconf: A test configuration file to set up the program parameters
-american-english: A full test dictionary from Ubuntu
-check.h: The given check header file for check.o
-testdict.txt: A smaller test dictionary for testing purposes
-ErrorChecking.c: Used to check user input and argc parameters
-ErrorChecking.h: Header file for ErrorChecking
-FileIO.c: Holds all code for reading in the user/spellconfig and dictionary
           file as well as the writing out to a user file
-FileIO.h: Header file for FileIO
-FreeMem.c: Used to free memory for the SpellConf struct and user/dictionary
            array
-FreeMem.h: Header file for FreeMem
-FuncPointer.c: Sets up which submodule the callback function points to and
                gives the implementation for each submodule
-FuncPointer.h: Header file for FuncPointer
-LinkedList.c: Implementation for a linked list struct that is used to hold
               a split up user file and dictionary file
-LinkedList.h: Header file for Linkedlist
-main.c: Runs the through the program
-main.h: Header file for main
-makefile: makes the program
-SpellConf.h: Header file that holds the SpellConf struct
-TestUserFile: A test user file

Assignment Completion:
I attempted to have all functionality of the assignment working and to my
knowledge it all works correctly.

List of bugs:
- If maxdif isnt an int it'll use the wrong value but produce no memory leaks
- If user/dict file is valid but empty valgrind errors will occur with no
  memory leaks

Lab Tested:
