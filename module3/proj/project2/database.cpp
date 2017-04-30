// database.cpp

#include "database.h"
#include "song.h"

// function definitions
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

void loadData(ifstream &inFile, Song songs[], int &size)
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

void writeData(const Song songs[], int &size, ofstream &outFile)					//	function to write data out to file
{
	for (int i = 0; i < size; i++){
		outFile << songs[i].title << ";" << songs[i].artist << ";" << songs[i].durationMin << ";" << songs[i].durationSec << ";" << songs[i].album << endl;
	}
	outFile.close();
	return;
}
