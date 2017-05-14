// song.cpp
#include "song.h"

// function definitions
Song::Song()
{
	strcpy(title, "Untitled");
	strcpy(artist, "Not Applicable");
	this->durationMin = -1;
	this->durationSec = -1;
	strcpy(album, "Untitled");
}

Song::Song(char aTitle[], char aArtist[], int aDurationMin, int aDurationSec, char aAlbum[])
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

void Song::setTitle(char aTitle[])
{
	strcpy(title, aTitle);
}

void Song::setArtist(char aArtist[])
{
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
	strcpy(album, aAlbum);
}

//prints formatted song for writing to file
void Song::writeSong(ofstream &outFile)
{
	outFile << title << ';' << artist << ';' << durationMin << ';' << durationSec << ';' << album << endl;
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
		return false;
	}
	else
	{
		return true;
	}
}

bool Song::compareAlbum(char searchQuery[])
{
	if (strstr(this->artist, searchQuery) != NULL)
        {
                return false;
        }
        else
        {
                return true;
        }
}
