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
		char* title;
		char* artist;
		char* album;
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
		// destructor
		~Song();

		// accessor functions
		void printSongInfo();
		void getTitle(char *);
		void getArtist(char *);
		void getDuration();
		void getAlbum(char *);
		bool compareArtist(char []);
		bool compareAlbum(char []);
		int getTitleLen();

		// mutator functions
		void setTitle(char []);
		void setArtist(char []);
		void setDurationMin(int);
		void setDurationSec(int);
		void setAlbum(char []);
		void writeSong(ofstream &);

		// operator functions (ORM)
		const Song& operator=(const Song&);
		//friend ostream& operator<<(ostream&, const Song&);
};

#endif
