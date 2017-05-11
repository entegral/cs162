// song.h
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// constants
const int CAP = 100;
const int MAXCHAR = 101;

class Song
{
	private:
		char title[MAXCHAR];
		char artist[MAXCHAR];
		char album[MAXCHAR];
		int durationMin;
		int durationSec;

// add custom and default constructor for Songs
// add mutator and accessor functions for songs
//	 	- mutators - setTitle(), setArtist(), setDurationMin(), setDurationSec(), setAlbum()
	public:
		// constructor
		song();
		// constructor with params
		song(char [], char [], int, int, char []);

		// accessor functions
		void printSongInfo();

		// mutator functions
		void setTitle(char []);
		void setArtist(char []);
		void setDurationMin(int);
		void setDurationSec(int);
		void setAlbum(char []);
		void writeSong(ofstream &);
};


// main function prototypes
void printMenu();
bool quitProgram();

// tool prototypes
int intInput();
char charInput();
void charArrayInput(char input[]);

// database funtion prototypes
void openFile(char [], ofstream &);
void writeData(const Song [], int &, ofstream &);
void openFile(char [], ifstream &);
void loadData(ifstream &, Song[], int &);

#endif
