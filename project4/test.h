// test.h
#ifndef test_h
#define test_h

#include <iostream>
#include <cstring>
using namespace std;

// constants
const int CAP = 100;
const int MAXCHAR = 101;

// function prototypes
void printMenu();
bool quitProgram();

// tool prototypes
int intInput();
char charInput();
void charArrayInput(char input[]);

#endif
