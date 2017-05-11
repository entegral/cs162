// database.cpp
#include "song.h"

// function definitions

// assign a filename to an object so that data can be read from a file
void openFile(char fileName[], ifstream &inFile)
{
	inFile.open(fileName);
	if(!inFile)
	{
		cout << "File did not open, exiting program" << endl;
		exit(0);
	}
	return;
}

// assign a filename to an object so memory data can be written out to file
void openFile(char fileName[], ofstream &outFile)
{
	outFile.open(fileName);
	if(!outFile)
	{
		cout << "outFile did not open, exiting program" << endl;
		exit(0);
	}
	return;
}

// load song data from file: pass in song array, ifstream object, and the counter for the array size
void loadData(ifstream &inFile, SongList songs, int &size)
{
	inFile.get(songs[size].title, MAXCHAR, ';');
	while(inFile)
	{
		inFile.ignore(100, ';');
		inFile.get(songs[size].artist, MAXCHAR, ';');
		inFile.ignore(100, ';');
		inFile >> songs[size].durationMin;
		inFile.ignore(100, ';');
		inFile >> songs[size].durationSec;
		inFile.ignore(100, ';');
		inFile.getline(songs[size].album, MAXCHAR);
		size++;
		inFile.get(songs[size].title, MAXCHAR, ';');
	}
	inFile.close();
	return;
}

// iterate through a song array and write that data out to a file per the requested formatting
void writeData(const Song songs[], int &size, ofstream &outFile)					//	function to write data out to file
{
	for (int i = 0; i < size; i++){
		outFile << songs[i].title << ";" << songs[i].artist << ";" << songs[i].durationMin << ";" << songs[i].durationSec << ";" << songs[i].album << endl;
	}
	outFile.close();
	return;
}
