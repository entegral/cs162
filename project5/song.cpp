// song.cpp
#include "song.h"

// function definitions
Song::Song()
{
	title = new char[MAXCHAR];
	strcpy(title, "untitled");
	artist = new char[MAXCHAR];
	strcpy(artist, "noArtist");
	durationMin = -1;
	durationSec = -1;
	album = new char[MAXCHAR];
	strcpy(album, "noAlbum" );
}

Song::Song(char aTitle[], char aArtist[], int aDurationMin, int aDurationSec, char aAlbum[])
{
	title = new char[strlen(aTitle) + 1];
	artist = new char[strlen(aArtist) + 1];
	strcpy(title, aTitle);
	strcpy(artist, aArtist);
	durationMin = aDurationMin;
	durationSec = aDurationSec;
	album = new char[strlen(aAlbum) + 1];
	strcpy(album, aAlbum);
}

Song::~Song()
{

	if(title){
		delete [] title;
		title = NULL;
	}

	if(artist){
		delete [] artist;
		artist = NULL;
	}

	if(album){
		delete [] album;
		album = NULL;
	}
}

void Song::printSongInfo()
{
	cout << "\nTitle: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Duration: " << durationMin << ":" << durationSec << endl;
	cout << "Album: " << album << endl;
}

void Song::setTitle(char aTitle[])
{
	if(title){
		delete [] title;
		title = NULL;
	}
	title = new char[strlen(aTitle) + 1];
	strcpy(title, aTitle);
}

void Song::setArtist(char aArtist[])
{
	if(artist){
		delete [] artist;
		artist = NULL;
	}
	artist = new char[strlen(aArtist) + 1];
	strcpy(artist, aArtist);
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
	if(album){
		delete [] album;
		album = NULL;
	}
	album = new char[strlen(aAlbum) + 1];
	strcpy(album, aAlbum);
}

void Song::getTitle(char *temp)
{
	for (int i = 0; i <= strlen(title); i++){
		temp[i] = title[i];
	}
}

int Song::getTitleLen()
{
	return strlen(title);
}

void Song::getArtist(char *temp)
{
	for (int i = 0; i <= strlen(temp); i++){
		temp[i] = artist[i];
	}
}

void Song::getDuration()
{
	cout << "Duration: " << durationMin << ":" << durationSec << endl;
}

void Song::getAlbum(char *temp)
{
	for (int i = 0; i <= strlen(temp); i++){
		temp[i] = album[i];
	}
}

bool Song::compareTitle(char *searchQuery)
{
	if (strstr(title, searchQuery) != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Song::compareArtist(char searchQuery[])
{
	if (strstr(artist, searchQuery) != NULL)
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
	if (strstr(album, searchQuery) != NULL)
        {
                return true;
        }
        else
        {
                return false;
        }
}

const Song& Song::operator=(const Song& aSong)
{
	if (this == &aSong)
	{
		return *this;
	}
	strcpy(title,aSong.title);				// stringcopy
	strcpy(artist,aSong.artist);
	durationMin = aSong.durationMin;
	durationSec = aSong.durationSec;
	strcpy(album,aSong.album);
	return *this;
}

ostream& operator<< (ostream& os, const Song& aSong)
{
	os << aSong.title << ';' << aSong.artist << ';' << aSong.durationMin << ';' << aSong.durationSec << ';' << aSong.album << endl;
	return os;
}
