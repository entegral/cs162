// song.cpp
#include "song.h"

// function definitions
Song::Song()
{
	title = new char[strlen("untitled") + 1];
	strcpy(title, "untitled");
	artist = new char[strlen("no artist")+1];
	strcpy(artist, "no artist");
	durationMin = -1;
	durationSec = -1;
	album = new char[strlen("no album") + 1];
	strcpy(album, "no album" );
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
	if(title != "untitled"){
		delete [] title;
		title = NULL;
	}

	if(artist != "no artist"){
		delete [] artist;
		artist = NULL;
	}

	if(album != "no album"){
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
	if(title != NULL){
		delete [] title;
		title = NULL;
	}
	title = new char[strlen(aTitle) + 1];
	strcpy(title, aTitle);
}

void Song::setArtist(char aArtist[])
{
	if(artist != NULL){
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
	if(album != NULL){
		delete [] album;
		album = NULL;
	}
	album = new char[strlen(aAlbum) + 1];
	strcpy(album, aAlbum);
}

//prints formatted song for writing to file
void Song::writeSong(ofstream &outFile)
{
	outFile << title << ';' << artist << ';' << durationMin << ';' << durationSec << ';' << album << endl;
}

void Song::getTitle()
{
	cout << "Title: " << title << endl;
}

void Song::getArtist()
{
	cout << "Artist: " << artist << endl;
}

void Song::getDuration()
{
		cout << "Duration: " << durationMin << ":" << durationSec << endl;
}

void Song::getAlbum()
{
	cout << "Album: " << album << endl;
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

//ostream& Song::operator<< (ostream& os, const Song& aSong)
//{
//	os << aSong.title << ';' << aSong.artist << ';' << aSong.durationMin << ';' << aSong.durationSec << ';' << aSong.album << endl;
//	return os;
//}
