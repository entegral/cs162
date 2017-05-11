// song.cpp
#include "song.h"


// function definitions
Song::song()
{
	strcpy(title, "Untitled");
	strcpy(artist, "Not Applicable");
	this->durationMin = -1;
	this->durationSec = -1;
	strcpy(Album, "Untitled");
}

Song::song(char aTitle[], char aArtist, int aDurationMin, int aDurationSec, char aAlbum[])
{
	strcpy(title, aTitle);
	strcpy(title, aArtist);
	this->durationMin = aDurationMin;
	this->durationSec = aDurationSec;
	strcpy(title, aAlbum);
}

void Song::printSongInfo()
{
	cout << "\nTitle: " << this->title << endl;
	cout << "Artist: " << this->artist << endl;
	cout << "Duration: " << this->durationMin << ":" << this->durationSec << endl;
	cout << "Album: " << this->album << endl;
	cout << endl;
}

void Song::setTitle(aTitle)
{
	strcpy(title, aTitle);
}

void Song::setArtist(aArtist)
{
	strcpy(artist, aArtist);
}

void Song::setDurationMin(aDurationMin)
{
	durationMin = aDurationMin;
}

void Song::setDurationSec(aDurationSec)
{
	durationSec = aDurationSec;
}

void Song::setAlbum(aAlbum)
{
	strcpy(album, aAlbum);
}
