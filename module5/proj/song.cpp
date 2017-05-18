// song.cpp
#include "song.h"

// function definitions
Song::Song()
{
	title = new char[strlen("Untitled") + 1];
	strcpy(this->title, title);
	artist = new char[strlen("No Artist")+1];
	strcpy(this->artist, artist);
	this->durationMin = -1;
	this->durationSec = -1;
	album = new char[strlen("No Album") + 1];
	strcpy(this->album, album);
}

Song::Song(char aTitle[], char aArtist[], int aDurationMin, int aDurationSec, char aAlbum[])
{
	this->title = new char[strlen(aTitle) + 1];
	this->artist = new char[strlen(aArtist) + 1];
	strcpy(this->title, aTitle);
	strcpy(this->artist, aArtist);
	this->durationMin = aDurationMin;
	this->durationSec = aDurationSec;
	this->album = new char[strlen(aAlbum) + 1];
	strcpy(this->album, aAlbum);
}

Song::~Song()
{
	if(title != NULL){
		delete [] title;
	}

	if(artist != NULL){
		delete [] artist;
	}

	if(album != NULL){
		delete [] album;
	}	
}

void Song::printSongInfo()
{
	cout << "\nTitle: " << this->title << endl;
	cout << "Artist: " << this->artist << endl;
	cout << "Duration: " << this->durationMin << ":" << this->durationSec << endl;
	cout << "Album: " << this->album << endl;
}

void Song::setTitle(char aTitle[])
{	
	if(this->title != NULL){
		delete [] this->title;
	}
	this->title = new char[strlen(aTitle) + 1];
	strcpy(this->title, aTitle);
}

void Song::setArtist(char aArtist[])
{
	if(this->artist != NULL){
		delete [] this->artist;
	}
	this->artist = new char[strlen(aArtist) + 1];
	strcpy(this->artist, aArtist);
}

void Song::setDurationMin(int aDurationMin)
{
	durationMin = aDurationMin;
}

void Song::setDurationSec(int aDurationSec)
{
	durationSec = aDurationSec;
}

void Song::setAlbum(char aAlbum[])
{
	if(this->album != NULL){
		delete [] this->album;
	}
	this->album = new char[strlen(aAlbum) + 1];
	strcpy(this->album, aAlbum);
}

//prints formatted song for writing to file
void Song::writeSong(ofstream &outFile)
{
	outFile << this->title << ';' << this->artist << ';' << durationMin << ';' << durationSec << ';' << this->album << endl;
}

void Song::getTitle()
{
	cout << "Title: " << this->title << endl;
}

void Song::getArtist()
{
	cout << "Artist: " << this->artist << endl;
}

void Song::getDuration()
{
		cout << "Duration: " << this->durationMin << ":" << this->durationSec << endl;
}

void Song::getAlbum()
{
	cout << "Album: " << this->album << endl;
}

bool Song::compareArtist(char searchQuery[])
{
	if (strstr(this->artist, searchQuery) != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Song::compareAlbum(char searchQuery[])
{
	if (strstr(this->album, searchQuery) != NULL)
        {
                return true;
        }
        else
        {
                return false;
        }
}
