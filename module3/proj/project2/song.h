// song.h
#ifndef song_h
#define song_h
#include "main.h"

struct Song
{
	char title[MAXCHAR] = {'\0'};
	char artist[MAXCHAR] = {'\0'};
	char album[MAXCHAR] = {'\0'};
	int durationMin;
	int durationSec;
};

// function prototypes
void displayLibrary(Song[], int &);
void addToLibrary(Song[], int &);
void removeFromLibrary(Song [], int &);
void searchForSongs(Song [], int &);
char charInput();
void charArrayInput(char input[]);
int intInput();


#endif
