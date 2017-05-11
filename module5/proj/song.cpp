// song.cpp
#include "song.h"


// function definitions
Song::song()
{
	this->title = '\0';
	this->artist = '\0';
	this->durationMin = -1;
	this->durationSec = -1;
	this->album = '\0';
}

Song::song(char aTitle[], char aArtist, int aDurationMin, int aDurationSec, char aAlbum[])
{
	this->title = aTitle;
	this->artist = aArtist;
	this->durationMin = aDurationMin;
	this->durationSec = aDurationSec;
	this->album = aAlbum;
}

Song::printSongInfo()
{
	cout << "\nTitle: " << this->title << endl;
	cout << "Artist: " << this->artist << endl;
	cout << "Duration: " << this->durationMin << ":" << this->durationSec << endl;
	cout << "Album: " << this->album << endl;
	cout << endl;
}
