// song.h
#ifndef song_h
#define song_h
#include "main.h"

class Song
{
	private:
		char title[MAXCHAR] = {'\0'};
		char artist[MAXCHAR] = {'\0'};
		char album[MAXCHAR] = {'\0'};
		int durationMin;
		int durationSec;
	public:
							// add custom and default constructor for Songs
							// add mutator and accessor functions for songs
};

class SongList
{
	private:
		Song List[CAP];

	public:
		void displayLibrary(Song[], int &);i
		void addToLibrary(Song[], int &);
		void removeFromLibrary(Song [], int &);
		void searchForSongs(Song [], int &);
}

int intInput();
char charInput();
void charArrayInput(char input[]);

#endif
