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
		Song();
		// constructor with params
		Song(char [], char [], int, int, char []);

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

#endif
