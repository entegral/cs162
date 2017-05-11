// song.h
#ifndef song_h
#define song_h
#include "main.h"

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
		song();
		song(char [], char [], int, int, char []);
		void printSongInfo()
};


#endif
