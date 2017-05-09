// database.h
#ifndef database_h
#define database_h
#include <fstream>
#include "song.h"
#include "main.h"

// funtion prototypes
void openFile(char [], ofstream &);
void writeData(const Song [], int &, ofstream &);
void openFile(char [], ifstream &);
void loadData(ifstream &, Song[], int &);

#endif
