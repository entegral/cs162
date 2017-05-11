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
		songList();
		songList(char fileName[]);
		// destructors
		~songList();

        void addToLibrary(Song[], int &);
		void displayLibrary(Song[], int &);
		void removeFromLibrary(Song [], int &);
		void searchForSongs(Song [], int &);
};


#endif
