#ifndef VIDEOLIST_H
#define VIDEOLIST_H

#include "song.h"

// define SongList class and for array and library size

class SongList
{
	private:
		Song list[CAP];
        int size;

	public:
		// constructors
		SongList();
		SongList(char fileName[]);
		// destructors
		~SongList();

        void addToLibrary();
		void displayLibrary();
		void removeFromLibrary();
		// void searchForSongs();
		void writeData(char []);
};


#endif
